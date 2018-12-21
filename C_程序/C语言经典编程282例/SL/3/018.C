#include <stdio.h>
#include <math.h>

void main()
{
    float a, b, c;
    float s, area;
    scanf("%f,%f,%f", &a, &b, &c); /*输入三条边*/
    if (a + b > c && b + c > a && a + c > b)					/*判断两边之和是否大于第三边*/
    {
        s = (a + b + c) / 2;
        area = (float)sqrt(s *(s - a)*(s - b)*(s - c)); 		/*计算三角形的面积*/
        printf("面积是:%f\n", area); 							/*输出三角形的面积*/
        if (a == b && a == c)									/*判断三条边是否相等*/
            printf("等边三角形\n");
         													/*输出等边三角形*/
        else if (a == b || a == c || b == c)
         													/*判断三角形中是否有两边相等*/
            printf("等腰三角形\n");
         													/*输出等腰三角形*/
        else if ((a *a + b * b == c *c) || (a *a + c * c == b *b) || (b *b + c
            * c == a *a))
         	/*判断是否有两边的平方和大于第三边的平方*/
            printf("直角三角形\n");
        													/*输出直角三角形*/
        else
            printf("普通三角形");
         													/*普通三角形*/
    }
    else
        printf("不能构成三角形");
     	/*如果两边之和小于第三边不能组成三角形*/
}
