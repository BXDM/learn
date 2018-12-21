#include<stdio.h>
#include<stdlib.h>

void main()
{
    struct com											/*定义商品信息的结构体*/
    {
        int num;										/*编号*/
        char *name;										/*商品名称*/
        int count;										/*数量*/
        double price;									/*单价*/
    }*commodity;
    commodity=(struct com*)malloc(sizeof(struct com));	/*分配内存空间*/
    commodity->num=1001;								/*赋值商品编号*/
    commodity->name="苹果";								/*赋值商品名称*/
    commodity->count=100;								/*赋值商品数量*/
    commodity->price=2.1;								/*赋值单价*/
    printf("编号=%d\n名称=%s\n数量=%d\n价格=%f\n",
        commodity->num,commodity->name,commodity->count,commodity->price);
}