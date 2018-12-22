#include <stdio.h>
#include <time.h>
#define Max 11
#define N 8
int hashtable[Max];

int func(int value)
{
    return value % Max; 								/*哈希函数*/
}

int search(int key) 									/*自定义函数实现哈希查询*/
{
    int pos, t;
    pos = func(key); 									/*哈希函数确定出的位置*/
    t = pos;										/*t存放确定出的位置*/
    while (hashtable[t] != key && hashtable[t] !=  - 1)
     											/*如果该位置上不等于要查找的关键字且不为空*/
    {
        t = (t + 1) % Max; 								/*利用线性探测求出下一个位置*/
        if (pos == t)
         /*如果经多次探测又回到原来用哈希函数求出的位置则说明要查找的数不存在*/
            return  - 1;
    }
    if (hashtable[t] ==  - 1)
     										/*如果探测的位置是-1则说明要查找的数不存在*/
        return NULL;
    else
        return t;
}

void creathash(int key)								/*自定义函数创建哈希表*/
{
    int pos, t;
    pos = func(key);								/*哈希函数确定元素的位置*/
    t = pos;
    while (hashtable[t] !=  - 1)
     										/*如果该位置有元素存在则进行线性探测再散列*/
    {
        t = (t + 1) % Max;
        if (pos == t)
        /*如果冲突处理后确定的位置与原位置相同则说明哈希表已满*/
        {
            printf("哈希表已满\n");
            return ;
        }
    }
    hashtable[t] = key;								/*将元素放入确定的位置*/
}

void main()
{
    int flag[50];
    int i, j, t;
    for (i = 0; i < Max; i++)
        hashtable[i] =  - 1;
     										/*哈希表中初始位置全置-1*/
    for (i = 0; i < 50; i++)
        flag[i] = 0;
     										/*50以内所有数未产生时均标志为0*/
    srand((unsigned long)time(0)); 					/*利用系统时间做种子产生随机数*/
    i = 0;
    while (i != N)
    {
        t = rand() % 50; 							/*产生一个50以内的随机数赋给t*/
        if (flag[t] == 0)
         										/*查看t是否产生过*/
        {
            creathash(t);							/*调用函数创建哈希表*/
            printf("%2d:", t); 						/*将该元素输出*/
            for (j = 0; j < Max; j++)
                printf("(%2d) ", hashtable[j]);
             									/*输出哈希表中内容*/
            printf("\n");
            flag[t] = 1; 							/*将产生的这个数标志为1*/
            i++;								/*i自加*/
        }
    }
    printf("请输入你想查找的元素:");
    scanf("%d", &t); 								/*输入要查找的元素*/
    if (t > 0 && t < 50)
    {
        i = search(t);								/*调用search进行哈希查找*/
        if (i !=  - 1)
            printf("查找成功！其位置是:%d\n", i);
         										/*若查找到该元素则输出其位置*/
        else
            printf("查找失败!");
         											/*未找到输出提示信息*/
    }
    else
        printf("输入有误!");
}

