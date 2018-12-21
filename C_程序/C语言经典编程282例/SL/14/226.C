#include<stdio.h>
#include<stdlib.h>

int main()
{
    int **pArray2;										/*二维数组指针*/
    int iIndex1,iIndex2;									/*循环控制变量*/
    pArray2=(int**)malloc(sizeof(int*[3]));					/*指向指针的指针*/
    for(iIndex1=0;iIndex1<3;iIndex1++)
    {
        *(pArray2+iIndex1)=(int*)malloc(sizeof(int[3]));
        for(iIndex2=0;iIndex2<3;iIndex2++)
        {
            *(*(pArray2+iIndex1)+iIndex2)=iIndex1+iIndex2;
        }
    }
    /*输出二维数组中的数据内容*/
    for(iIndex1=0;iIndex1<3;iIndex1++)
    {
        for(iIndex2=0;iIndex2<3;iIndex2++)
        {
            printf("%d\t",*(*(pArray2+iIndex1)+iIndex2));
        }
        printf("\n");
    }
    return 0;
}

