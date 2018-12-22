/********************************************************************/ 
/* DES(Data Encryption Standard) */ 
/* Written by Bunny */ 
/* Banyet Soft Labs. 1999 */ 
/* ALL RIGHTS RESERVED! */ 
/* 注意! 版权所有! 可以自由转载,但不得加以修改或删除! */ 
/* E-mail:Assassin@ynmail.com http://assassin.yeah.net/ */ 
/********************************************************************/ 

/**************************************************************************/ 
/*注意:这只是标准DES算法的例子,所以速度并不是很快,不适用于大量数据加密的场*/ 
/*合.UNIX的密码也采用DES,不过它在里面加了点其它的东西.所以结果和DES的结果 */ 
/*不一样. 由于使用了WINDOWS类库,所以必须在WINDOWS环境下编译. */ 
/**************************************************************************/ 

#include 
#include 
#include 
#include 
#include "Schedle.h" 

class CShift{ 
public: 
DWORDLONG mask[16]; 
int step[16]; 
CShift(){ 
for(int i=0;i<16;i++){ 
step=2; 
mask=0xc000000; 
} 
step[0]=step[1]=step[8]=step[15]=1; 
mask[0]=mask[1]=mask[8]=mask[15]=0x8000000; 
} 
}; 

class CDES{ 

public: 

CDES(){ 
m_dwlKey=0; 
m_dwlData=0; 
ConvertTableToMask(dwlKey_PC_1,64); 
//PrintTable(dwlKey_PC_1,7,8); 
ConvertTableToMask(dwlKey_PC_2,56); 
ConvertTableToMask(dwlData_IP,64); 
ConvertTableToMask(dwlData_Expansion,32); 
ConvertTableToMask(dwlData_FP,64); 
ConvertTableToMask(dwlData_P,32); 
Generate_S(); 

} 
void PrintBit(DWORDLONG); 
void EncryptKey(char *); 
unsigned char* EncryptData(unsigned char *); 
unsigned char* DescryptData(unsigned char*); 

private: 
void ConvertTableToMask(DWORDLONG *,int); 
void Generate_S(void); 
void PrintTable(DWORDLONG*,int,int); 
DWORDLONG ProcessByte(unsigned char*,BOOL); 
DWORDLONG PermuteTable(DWORDLONG,DWORDLONG*,int); 
void Generate_K(void); 
void EncryptKernel(void); 
DWORDLONG Generate_B(DWORDLONG,DWORDLONG*); 
/*For verify schedule permutation only*/ 
DWORDLONG UnPermuteTable(DWORDLONG,DWORDLONG*,int); 
/**************************************/ 
DWORDLONG dwlData_S[9][4][16]; 
CShift m_shift; 
DWORDLONG m_dwlKey; 
DWORDLONG m_dwlData; 
DWORDLONG m_dwl_K[17]; 
}; 

void CDES::EncryptKey(char *key){ 

printf("\nOriginal Key: %s",key); 
m_dwlKey=ProcessByte((unsigned char*)key,TRUE); 
// PrintBit(m_dwlKey); 
m_dwlKey=PermuteTable(m_dwlKey,dwlKey_PC_1,56); 
// PrintBit(m_dwlKey); 
Generate_K(); 
// printf("\n******************************************\n"); 
} 

void CDES::Generate_K(void){ 

DWORDLONG C[17],D[17],tmp; 

C[0]=m_dwlKey>>28; 
D[0]=m_dwlKey&0xfffffff; 

for(int i=1;i<=16;i++){ 
tmp=(C[i-1]&m_shift.mask[i-1])>>(28-m_shift.step[i-1]); 
C=((C[i-1]< tmp=(D[i-1]&m_shift.mask[i-1])>>(28-m_shift.step[i-1]); 
D=((D[i-1]< m_dwl_K=(C<<28)|D; 
m_dwl_K=PermuteTable(m_dwl_K,dwlKey_PC_2,48); 
} 
} 

DWORDLONG CDES::ProcessByte(unsigned char *key,BOOL shift){ 

unsigned char tmp; 
DWORDLONG byte=0; 
int i=0; 

while(i<8){ 
while(*key){ 
if(byte!=0) 
byte<<=8; 
tmp=*key; 
if(shift) 
tmp<<=1; 
byte|=tmp; 
i++; 
key++; 
} 
if(i<8) 
byte<<=8; 
i++; 
} 
return byte; 
} 

DWORDLONG CDES::PermuteTable(DWORDLONG dwlPara,DWORDLONG* dwlTable,int nDestLen){ 

int i=0; 
DWORDLONG tmp=0,moveBit; 

while(i moveBit=1; 
if(dwlTable&dwlPara){ 
moveBit<<=nDestLen-i-1; 
tmp|=moveBit; 
} 
i++; 
} 
return tmp; 
} 

DWORDLONG CDES::UnPermuteTable(DWORDLONG dwlPara,DWORDLONG* dwlTable,int nDestLen){ 

DWORDLONG tmp=0; 
int i=nDestLen-1; 

while(dwlPara!=0){ 
if(dwlPara&0x01) 
tmp|=dwlTable; 
dwlPara>>=1; 
i--; 
} 
return tmp; 
} 

void CDES::PrintTable(DWORDLONG *dwlPara,int col,int row){ 

int i,j; 
for(i=0;i printf("\n"); 
getch(); 
for(j=0;j PrintBit(dwlPara[i*col+j]); 
} 
} 

void CDES::PrintBit(DWORDLONG bitstream){ 

char out[76]; 
int i=0,j=0,space=0; 

while(bitstream!=0){ 
if(bitstream&0x01) 
out[i++]='1'; 
else 
out[i++]='0'; 
j++; 
if(j%8==0){ 
out[i++]=' '; 
space++; 
} 

bitstream=bitstream>>1; 
} 
out='\0'; 
strcpy(out,strrev(out)); 
printf("%s **:%d\n",out,i-space); 
} 

void CDES::ConvertTableToMask(DWORDLONG *mask,int max){ 

int i=0; 
DWORDLONG nBit=1; 

while(mask!=0){ 
nBit=1; 
nBit<<=max-mask; 
mask[i++]=nBit; 
} 
} 

void CDES::Generate_S(void){ 

int i; 
int j,m,n; 
m=n=0; 
j=1; 

for(i=0;i<512;i++){ 
dwlData_S[j][m][n]=OS; 
n=(n+1)%16; 
if(!n){ 
m=(m+1)%4; 
if(!m) 
j++; 
} 
} 
} 

unsigned char * CDES::EncryptData(unsigned char *block){ 

unsigned char *EncrytedData=new unsigned char(15); 

printf("\nOriginal Data: %s\n",block); 
m_dwlData=ProcessByte(block,0); 
// PrintBit(m_dwlData); 
m_dwlData=PermuteTable(m_dwlData,dwlData_IP,64); 
EncryptKernel(); 
// PrintBit(m_dwlData); 
DWORDLONG bit6=m_dwlData; 
for(int i=0;i<11;i++){ 
EncrytedData[7-i]=(unsigned char)(bit6&0x3f)+46; 
bit6>>=6; 
} 
EncrytedData[11]='\0'; 
printf("\nAfter Encrypted: %s",EncrytedData); 

for(i=0;i<8;i++){ 
EncrytedData[7-i]=(unsigned char)(m_dwlData&0xff); 
m_dwlData>>=8; 
} 
EncrytedData[8]='\0'; 


return EncrytedData; 
} 

void CDES::EncryptKernel(void){ 

int i=1; 

DWORDLONG L[17],R[17],B[9],EK,PSB; 
L[0]=m_dwlData>>32; 
R[0]=m_dwlData&0xffffffff; 

for(i=1;i<=16;i++){ 
L=R[i-1]; 
R[i-1]=PermuteTable(R[i-1],dwlData_Expansion,48); //Expansion R 
EK=R[i-1]^m_dwl_K; //E Permutation 
PSB=Generate_B(EK,B); //P Permutation 
R=L[i-1]^PSB; 
} 

R[16]<<=32; 
m_dwlData=R[16]|L[16]; 
m_dwlData=PermuteTable(m_dwlData,dwlData_FP,64); 
} 

unsigned char* CDES::DescryptData(unsigned char *desData){ 

int i=1; 
unsigned char *DescryptedData=new unsigned char(15); 
DWORDLONG L[17],R[17],B[9],EK,PSB; 
DWORDLONG dataPara; 

dataPara=ProcessByte(desData,0); 
dataPara=PermuteTable(dataPara,dwlData_IP,64); 

R[16]=dataPara>>32; 
L[16]=dataPara&0xffffffff; 

for(i=16;i>=1;i--){ 
R[i-1]=L; 
L=PermuteTable(L,dwlData_Expansion,48); //Expansion L 
EK=L^m_dwl_K; //E Permutation 
PSB=Generate_B(EK,B); //P Permutation 
L[i-1]=R^PSB; 
} 

L[0]<<=32; 
dataPara=L[0]|R[0]; 
dataPara=PermuteTable(dataPara,dwlData_FP,64); 

// PrintBit(dataPara); 

for(i=0;i<8;i++){ 
DescryptedData[7-i]=(unsigned char)(dataPara&0xff); 
dataPara>>=8; 
} 
DescryptedData[8]='\0'; 
printf("\nAfter Decrypted: %s\n",DescryptedData); 

return DescryptedData; 
} 

DWORDLONG CDES::Generate_B(DWORDLONG EKPara,DWORDLONG *block){ 

int i,m,n; 
DWORDLONG tmp=0; 

for(i=8;i>0;i--){ 
block=EKPara&0x3f; 
m=(int)(block&0x20)>>4; 
m|=block&0x01; 
n=(int)(block<<1)>>2; 
block=dwlData_S[m][n]; 
EKPara>>=6; 
} 

for(i=1;i<=8;i++){ 
tmp|=block; 
tmp<<=4; 
} 
tmp>>=4; 
tmp=PermuteTable(tmp,dwlData_P,32); 

return tmp; 
} 

void main(void){ 

CDES des; 
des.EncryptKey("12345678"); 
unsigned char *result=des.EncryptData((unsigned char*)"DemoData"); 
des.DescryptData(result); 
} 
