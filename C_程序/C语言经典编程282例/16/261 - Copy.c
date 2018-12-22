#include "stdio.h"
#include "string.h"

#define SUCCESS  1
#define DESENCRY 1
#define DESDECRY 0

typedef int  INT32;
typedef char INT8;
typedef unsigned char  ULONG8;
typedef unsigned short ULONG16;
typedef unsigned long  ULONG32;

ULONG32 g_outkey[16][2] = { 0};/*输出的key*/
ULONG32 g_bufkey[2] = { 0};/*形成起始密钥*/

/*实现时采用查表方式,下面是定义的供查找用的表*/ 
static ULONG8 wz_lefttable[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

static ULONG32 wz_leftandtab[3] = {0x0 , 0x80000000 , 0xc0000000 } ;
static ULONG8 wz_keyleft[28] = 
{
  57,49,41,33,25,17,9,1,58,50,42,34,26,18,
  10,2,59,51,43,35,27,19,11,3,60,52,44,36
};

static ULONG8 wz_keyright[28] = {
  63,55,47,39,31,23,15,7,62,54,46,38,30,22,
  14,6,61,53,45,37,29,21,13,5,28,20,12,4
};

static ULONG8 wz_keychoose[48] ={
  14,17,11,24,1,5,3,28,15,6,21,10,
  23,19,12,4,26,8,16,7,27,20,13,2,
  41,52,31,37,47,55,30,40,51,45,33,48,
  44,49,39,56,34,53,46,42,50,36,29,32
};


/*最后一次调整*/
static ULONG8 wz_pc4[64] = {
  40,8,48,16,56,24,64,32, 39,7,47,15,55,23,63,31,
  38,6,46,14,54,22,62,30, 37,5,45,13,53,21,61,29,
  36,4,44,12,52,20,60,28, 35,3,43,11,51,19,59,27,
  34,2,42,10,50,18,58,26, 33,1,41,9,49,17,57,25
};


/*第一次转换时用*/
static ULONG8  wz_pc1[64] = {
  58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,
  62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,
  57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,
  61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7 
} ;

static ULONG8 wz_pc3[32] = {
  16,7,20,21, 29,12,28,17, 1,15,23,26,
  5,18,31,10, 2,8,24,14, 32,27,3,9,
  19,13,30,6, 22,11,4,25
} ;

static ULONG32  wz_pc2[64] = { 
  0x80000000L,0x40000000L,0x20000000L,0x10000000L, 0x8000000L, 
  0x4000000L, 0x2000000L, 0x1000000L, 0x800000L, 0x400000L,
        0x200000L, 0x100000L,  0x80000L, 0x40000L, 0x20000L,0x10000L, 
  0x8000L, 0x4000L, 0x2000L, 0x1000L, 0x800L, 0x400L, 0x200L,
  0x100L, 0x80L,0x40L,0x20L, 0x10L, 0x8L, 0x4L, 0x2L, 0x1L,
  0x80000000L,0x40000000L,0x20000000L,0x10000000L, 0x8000000L,
  0x4000000L, 0x2000000L, 0x1000000L, 0x800000L, 0x400000L,
        0x200000L, 0x100000L,  0x80000L, 0x40000L, 0x20000L, 0x10000L, 
  0x8000L, 0x4000L, 0x2000L, 0x1000L, 0x800L, 0x400L, 0x200L, 
  0x100L, 0x80L, 0x40L,0x20L, 0x10L, 0x8L,  0x4L, 0x2L, 0x1L,     
}; 

static ULONG8 exptab3[48] = {
  32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,
  12,13,14,15,16,17,16,17,18,19,20,21,
  20,21,22,23,24,25,24,25,26,27,28,29,
  28,29,30,31,32,1 
};

static ULONG8 SP[8][64] = 
{
 {
   0xe,0x0,0x4,0xf,0xd,0x7,0x1,0x4,0x2,0xe,0xf,0x2,0xb,
   0xd,0x8,0x1,0x3,0xa,0xa,0x6,0x6,0xc,0xc,0xb,0x5,0x9,
   0x9,0x5,0x0,0x3,0x7,0x8,0x4,0xf,0x1,0xc,0xe,0x8,0x8,
   0x2,0xd,0x4,0x6,0x9,0x2,0x1,0xb,0x7,0xf,0x5,0xc,0xb,
   0x9,0x3,0x7,0xe,0x3,0xa,0xa,0x0,0x5,0x6,0x0,0xd  
 },
 
 { 
   0xf,0x3,0x1,0xd,0x8,0x4,0xe,0x7,0x6,0xf,0xb,0x2,0x3,
   0x8,0x4,0xf,0x9,0xc,0x7,0x0,0x2,0x1,0xd,0xa,0xc,0x6,
   0x0,0x9,0x5,0xb,0xa,0x5,0x0,0xd,0xe,0x8,0x7,0xa,0xb,
   0x1,0xa,0x3,0x4,0xf,0xd,0x4,0x1,0x2,0x5,0xb,0x8,0x6,
   0xc,0x7,0x6,0xc,0x9,0x0,0x3,0x5,0x2,0xe,0xf,0x9
 },
 { 
   0xa,0xd,0x0,0x7,0x9,0x0,0xe,0x9,0x6,0x3,0x3,0x4,0xf,
   0x6,0x5,0xa,0x1,0x2,0xd,0x8,0xc,0x5,0x7,0xe,0xb,0xc,
   0x4,0xb,0x2,0xf,0x8,0x1,0xd,0x1,0x6,0xa,0x4,0xd,0x9,
   0x0,0x8,0x6,0xf,0x9,0x3,0x8,0x0,0x7,0xb,0x4,0x1,0xf,
   0x2,0xe,0xc,0x3,0x5,0xb,0xa,0x5,0xe,0x2,0x7,0xc                                          
 },
 { 
   0x7,0xd,0xd,0x8,0xe,0xb,0x3,0x5,0x0,0x6,0x6,0xf,0x9,
   0x0,0xa,0x3,0x1,0x4,0x2,0x7,0x8,0x2,0x5,0xc,0xb,0x1,
   0xc,0xa,0x4,0xe,0xf,0x9,0xa,0x3,0x6,0xf,0x9,0x0,0x0,
   0x6,0xc,0xa,0xb,0xa,0x7,0xd,0xd,0x8,0xf,0x9,0x1,0x4,
   0x3,0x5,0xe,0xb,0x5,0xc,0x2,0x7,0x8,0x2,0x4,0xe                         
 },
 { 
   0x2,0xe,0xc,0xb,0x4,0x2,0x1,0xc,0x7,0x4,0xa,0x7,0xb,
   0xd,0x6,0x1,0x8,0x5,0x5,0x0,0x3,0xf,0xf,0xa,0xd,0x3,
   0x0,0x9,0xe,0x8,0x9,0x6,0x4,0xb,0x2,0x8,0x1,0xc,0xb,
   0x7,0xa,0x1,0xd,0xe,0x7,0x2,0x8,0xd,0xf,0x6,0x9,0xf,
   0xc,0x0,0x5,0x9,0x6,0xa,0x3,0x4,0x0,0x5,0xe,0x3
 },
 { 
   0xc,0xa,0x1,0xf,0xa,0x4,0xf,0x2,0x9,0x7,0x2,0xc,0x6,
   0x9,0x8,0x5,0x0,0x6,0xd,0x1,0x3,0xd,0x4,0xe,0xe,0x0,
   0x7,0xb,0x5,0x3,0xb,0x8,0x9,0x4,0xe,0x3,0xf,0x2,0x5,
   0xc,0x2,0x9,0x8,0x5,0xc,0xf,0x3,0xa,0x7,0xb,0x0,0xe,
   0x4,0x1,0xa,0x7,0x1,0x6,0xd,0x0,0xb,0x8,0x6,0xd
 },
 { 
   0x4,0xd,0xb,0x0,0x2,0xb,0xe,0x7,0xf,0x4,0x0,0x9,0x8,
   0x1,0xd,0xa,0x3,0xe,0xc,0x3,0x9,0x5,0x7,0xc,0x5,0x2,
   0xa,0xf,0x6,0x8,0x1,0x6,0x1,0x6,0x4,0xb,0xb,0xd,0xd,
   0x8,0xc,0x1,0x3,0x4,0x7,0xa,0xe,0x7,0xa,0x9,0xf,0x5,
   0x6,0x0,0x8,0xf,0x0,0xe,0x5,0x2,0x9,0x3,0x2,0xc
 },
 { 
   0xd,0x1,0x2,0xf,0x8,0xd,0x4,0x8,0x6,0xa,0xf,0x3,0xb,
   0x7,0x1,0x4,0xa,0xc,0x9,0x5,0x3,0x6,0xe,0xb,0x5,0x0,
   0x0,0xe,0xc,0x9,0x7,0x2,0x7,0x2,0xb,0x1,0x4,0xe,0x1,
   0x7,0x9,0x4,0xc,0xa,0xe,0x8,0x2,0xd,0x0,0xf,0x6,0xc,
   0xa,0x9,0xd,0x0,0xf,0x3,0x3,0x5,0x5,0x6,0x8,0xb
 } 
};
INT32 Ddes(ULONG8 *data,ULONG8 *key,INT32 readlen);
INT32 des(ULONG8 *data, ULONG8 *key,INT32 readlen);
INT32 makefirstkey( ULONG32 *keyP );
INT32 handle_data(ULONG32 *left , ULONG8 choice);
INT32 makedata(ULONG32  *left ,ULONG32  *right ,ULONG32 number);
INT32 makekey(  ULONG32 *keyleft,ULONG32 *keyright ,ULONG32 number);
/*函数实现*/ 
INT32 DdesN(ULONG8 *data, ULONG8 **key, ULONG32 n_key,ULONG32 readlen)
{
 INT32 i ;
 for ( i = n_key ; i > 0 ; i--)
 {
  Ddes(data,key[i-1],readlen);
 }
 return SUCCESS;
}

INT32 desN(ULONG8 *data, ULONG8 **key, ULONG32 n_key,ULONG32 readlen)
{
 ULONG32 i = 0;
 for ( i = 0 ; i < n_key ; i++)
 {
  des(data,key[i],readlen);
 }
 return SUCCESS;
}

INT32 des3(ULONG8 *data, ULONG8 *key,ULONG32 n ,ULONG32 readlen)
{
 ULONG32 i = 0 , j = 0 ;
 makefirstkey((ULONG32*)key) ;  /*产生密钥*/
 for ( i = 0 ; i < n ; i++)
 {
  for ( j = 0 ; j < readlen ; j += 8)
  {
   handle_data( (ULONG32*)&data[j], DESENCRY );
  }
 }
 return SUCCESS;
}

INT32 Ddes3(ULONG8 *data,ULONG8 *key,ULONG32 n ,ULONG32 readlen)
{
 ULONG32 i = 0 , j = 0 ;
 makefirstkey((ULONG32*)key) ;  /*产生密钥*/
 for ( i = 0 ; i < n ; i++)
 {
  for ( j = 0 ; j < readlen ; j += 8)
  {
   handle_data( (ULONG32*)&data[j], DESDECRY );
  }
 }
 return SUCCESS;
}

INT32 des(ULONG8 *data, ULONG8 *key,INT32 readlen)
{
 INT32 i = 0;   
 makefirstkey((ULONG32*)key) ;  /*产生密钥*/
 for ( i = 0 ; i < readlen ; i += 8)
 {
  handle_data( (ULONG32*)&data[i], DESENCRY );
 }
 return SUCCESS;
}

INT32 Ddes(ULONG8 *data,ULONG8 *key,INT32 readlen)
{
 INT32 i = 0;
 makefirstkey((ULONG32*)key) ;  
 for ( i = 0 ; i < readlen ; i += 8)
 {
  handle_data( (ULONG32*)&data[i] ,DESDECRY);
 }
 return SUCCESS;
}

INT32 handle_data(ULONG32 *left , ULONG8 choice)
{
 INT32  number = 0 ,j = 0;   
 ULONG32 *right = &left[1] ;
 ULONG32 tmp = 0;       
 ULONG32 tmpbuf[2] = { 0 };             
 
 /*第一次调整wz_pc1[64]*/
 for ( j = 0 ; j < 64 ; j++)
 {
  if (j < 32 ) 
  {
   if ( wz_pc1[j] > 32)/*属于right*/
   {
    if ( *right&wz_pc2[wz_pc1[j]-1] )
    {
     tmpbuf[0] |= wz_pc2[j] ;
    }
   }
   else
   {
    if ( *left&wz_pc2[wz_pc1[j]-1] )
    {
     tmpbuf[0] |= wz_pc2[j] ;
    }
   }
  }
  else
  {
   if ( wz_pc1[j] > 32)/*属于right*/
   {
    if ( *right&wz_pc2[wz_pc1[j]-1] )
    {
     tmpbuf[1] |= wz_pc2[j] ;
    }
   }
   else
   {
    if ( *left&wz_pc2[wz_pc1[j]-1] )
    {
     tmpbuf[1] |= wz_pc2[j] ;
    }
   }
  }
 }
 *left  = tmpbuf[0] ;
 *right = tmpbuf[1];
 tmpbuf[0] = 0 ;
 tmpbuf[1] = 0 ;
    switch( choice )
 {
 case DESENCRY:
  for ( number = 0 ; number < 16 ; number++)
  {            
   makedata( left , right , (ULONG32)number) ;
  }
  break;
 case DESDECRY:
  for ( number = 15 ; number >= 0 ; number--)
  {            
   makedata( left , right ,(ULONG32)number) ;
  }
  break;
 default:
  break;
 }
 
 /*最后一轮操作不交换左右值*/
 
 tmp = *left ;
 *left = *right ;
 *right = tmp ;        
 
 /*最后一次调整wz_pc4[64]*/
 
 for ( j = 0 ; j < 64 ; j++)
 {
  if (j < 32 ) 
  {
   if ( wz_pc4[j] > 32)/*属于right*/
   {
    if ( *right&wz_pc2[wz_pc4[j]-1] )
    {
     tmpbuf[0] |= wz_pc2[j] ;
    }
   }
   else
   {
    if ( *left&wz_pc2[wz_pc4[j]-1] )
    {
     tmpbuf[0] |= wz_pc2[j] ;
    }
   }
  }
  else
  {
   if ( wz_pc4[j] > 32)/*属于right*/
   {
    if ( *right&wz_pc2[wz_pc4[j]-1] )
    {
     tmpbuf[1] |= wz_pc2[j] ;
    }
   }
   else
   {
    if ( *left&wz_pc2[wz_pc4[j]-1] )
    {
     tmpbuf[1] |= wz_pc2[j] ;
    }
   }
  }
 }
 
 *left =  tmpbuf[0] ;
 *right = tmpbuf[1];
 
 return SUCCESS;
}


INT32 makedata(ULONG32  *left ,ULONG32  *right ,ULONG32 number) 
{
 INT32 j; 
 ULONG32 oldright = *right;         
 ULONG8 rexpbuf[8] = { 0} ;
 ULONG32 datatmp = 0;        
 ULONG32 exp[2] = { 0} ;                         

 
 for ( j = 0 ; j < 48 ; j++)
 {
  /*两个32位，每个存放24位*/
  if ( j < 24 )
  {
   if ( *right&wz_pc2[exptab3[j]-1] )
   {
    exp[0] |= wz_pc2[j] ;
   }            
  }            
  else
  {
   if ( *right&wz_pc2[exptab3[j]-1] )
   {
    exp[1] |= wz_pc2[j-24] ;
   }
  }
 }
 
 for ( j = 0 ; j < 2 ; j++)
 {            
  exp[j] ^= g_outkey[number][j] ;
 }    
 
 /*由48－>32*/      
 
 exp[1] >>= 8 ;
 rexpbuf[7] = (ULONG8) (exp[1]&0x0000003fL) ;
 exp[1] >>= 6 ;
 rexpbuf[6] = (ULONG8) (exp[1]&0x0000003fL) ;
 exp[1] >>= 6 ;
 rexpbuf[5] = (ULONG8) (exp[1]&0x0000003fL) ;
 exp[1] >>= 6 ;
 rexpbuf[4] = (ULONG8) (exp[1]&0x0000003fL) ;
 exp[0]  >>=  8 ;
 rexpbuf[3] = (ULONG8) (exp[0]&0x0000003fL) ;     
 exp[0] >>= 6 ;
 rexpbuf[2] = (ULONG8) (exp[0]&0x0000003fL) ;
 exp[0] >>= 6 ;
 rexpbuf[1] = (ULONG8) (exp[0]&0x0000003fL) ;
 exp[0] >>= 6 ;
 rexpbuf[0] = (ULONG8) (exp[0]&0x0000003fL) ;     
 exp[0] = 0 ;
 exp[1] = 0 ;
 
 /*由48－> 32*/
 
 *right = 0 ;
 for ( j = 0 ; j < 7 ; j++)
 {
  *right |= SP[j][rexpbuf[j]] ;
  *right <<= 4 ;
 }
 *right |= SP[j][rexpbuf[j]] ;
 
 /*又要换位了*/
 
 datatmp = 0;
 for ( j = 0 ; j < 32 ; j++)
 {
  if ( *right&wz_pc2[wz_pc3[j]-1] )
  {
   datatmp |= wz_pc2[j] ;
  }
 }
 *right = datatmp ;
 
 /*一轮结束收尾操作*/                
 
 *right ^= *left;       
 *left = oldright;
 
 return SUCCESS;
}

INT32 makefirstkey( ULONG32 *keyP )
{
 ULONG32 key[2] = {0};
 ULONG32 *Pkey ;
 ULONG32 *Pbufkey ;
 INT32 j; 
 Pbufkey = (ULONG32*)g_bufkey ;
 Pkey = (ULONG32*)key;
 
 memset((ULONG8*)g_bufkey,0,sizeof(g_bufkey));    
 memcpy((ULONG8*)&key,(ULONG8*)keyP ,8) ;      
 memset((ULONG8*)g_outkey,0,sizeof(g_outkey));
 for(  j = 0 ; j < 28 ; j++)
 {
  if ( wz_keyleft[j] > 32 ) 
  {
   if ( Pkey[1]&wz_pc2[wz_keyleft[j]-1] )
   {
    Pbufkey[0] |= wz_pc2[j] ;
   }
  }
  else
  {
   if ( Pkey[0]&wz_pc2[wz_keyleft[j]-1] )
   {
    Pbufkey[0] |= wz_pc2[j] ;
   }
  }
  
  if ( wz_keyright[j] > 32 ) 
  {
   if ( Pkey[1]&wz_pc2[wz_keyright[j]-1] )
   {
    Pbufkey[1] |= wz_pc2[j];
   }
  }
  else
  {
   if ( Pkey[0]&wz_pc2[wz_keyright[j]-1] )
   {
    Pbufkey[1] |= wz_pc2[j];
   }
  }
 }
 for (j = 0 ; j < 16 ; j++)
 {
  makekey(&Pbufkey[0],&Pbufkey[1] , j ) ;
 }
 return SUCCESS;
}


INT32 makekey(  ULONG32 *keyleft,ULONG32 *keyright ,ULONG32 number)/*输入密钥的地址，一个32位的*/
{
 ULONG32 tmpkey[2] ={0};
 ULONG32 *Ptmpkey = (ULONG32*)tmpkey;     
 ULONG32 *Poutkey = (ULONG32*)&g_outkey[number]; 
 INT32 j;        
 memset((ULONG8*)tmpkey,0,sizeof(tmpkey));          
 /*要最高的一位或两位*/
 *Ptmpkey = *keyleft&wz_leftandtab[wz_lefttable[number]] ;           
 Ptmpkey[1] = *keyright&wz_leftandtab[wz_lefttable[number]] ;              
 if ( wz_lefttable[number] == 1)
 {
  *Ptmpkey >>= 27;
  Ptmpkey[1] >>= 27;
 }
 else
 {
  *Ptmpkey >>= 26;
  Ptmpkey[1] >>= 26;                    
 }
 Ptmpkey[0] &= 0xfffffff0;
 Ptmpkey[1] &= 0xfffffff0;
 /*得到高位的值*/
 *keyleft <<= wz_lefttable[number] ;
 *keyright <<= wz_lefttable[number] ;
 *keyleft |= Ptmpkey[0] ;
 *keyright |= Ptmpkey[1] ;            
 Ptmpkey[0] = 0;
 Ptmpkey[1] = 0;
    
 /*从56位中选出48位,3个16位*/
 for ( j = 0 ; j < 48 ; j++)
 {
  if ( j < 24 )
  {
   
   if ( *keyleft&wz_pc2[wz_keychoose[j]-1])
   {
    Poutkey[0] |= wz_pc2[j] ;
   }                   
  }            
  
  else /*j>=24*/
  {                   
   if ( *keyright&wz_pc2[(wz_keychoose[j]-28)])
   {
    Poutkey[1] |= wz_pc2[j-24] ;
   }                   
  }
 }
 return SUCCESS;
}

char * dectohex(int dec,int len)
{
 static char buf[32];
 int i=0;
 char cell[]="0123456789ABCDEF";
 memset (buf,0,32);
 memset (buf,'0',len);
 while(dec!=0)
 {
  buf[i++]=cell[dec%16];
  dec=dec/16;
 }
 strcat(buf,"x0");
 return(strrev(buf));
}
void main()
{
 int i;
 unsigned char input[256];
 unsigned char password[256];
 memset(input,0,256);
 memset(password,0,256);

 puts("\nPlease input the text to be encode:");
 gets(input);
 puts("\nPlease input the password:");
 gets(password);

 des(input, password,strlen(input));
 puts("\nthe encode result is:");
 for(i=0;i<strlen(input);i++)
 {
  if(i%9==0) puts("");
  printf("%s  ",input[i],2);
 }
 getch();

 Ddes(input,password,strlen(input));
 puts("\n\nthe decode result is:");
 puts(input);
 puts("\nPress any key to exit...");
 getch();
 
}
