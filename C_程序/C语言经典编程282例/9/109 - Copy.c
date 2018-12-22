#include<stdio.h>
main()
{
	char a[100], b[100], c[200],  *p;
	int i = 0, j = 0, k = 0;
	printf("please input string a:\n");
	scanf("%s", a); 									/*输入字符串1放入a数组中*/
	printf("please input string b:\n");
	scanf("%s", b); 									/*输入字符串2放入b数组中*/
	while (a[i] != '\0' && b[j] != '\0')
	{
		if (a[i] < b[j])									/*判断a中字符是否小于b中字符*/
		{
			c[k] = a[i]; 								/*如果小于，将a中字符放到数组c中*/
			i++; 									/*i自加*/
		}
		else
		{
			c[k] = b[j]; 								/*如不小于，将b中字符放到c中*/
			j++; 									/*j自加*/
		}
		k++; 										/*k自加*/
	}
	c[k] = '\0'; 										/*将两个字符串合并到c中后加结束符*/
	if (a[i] == '\0')									/*判断a中字符是否全都复制到c中*/
		p = b + j;									/*p指向数组b中未复制到c的位置*/
	else
		p = a + i;									/*p指向数组a中未复制到c的位置*/
	strcat(c, p); 									/*将p指向位置开始的字符串连接到c中*/
	puts(c); 										/*将c输出*/
}
