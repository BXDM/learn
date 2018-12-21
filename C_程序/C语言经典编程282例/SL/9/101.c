#include<stdio.h>
main()
{
	int i, v0 = 0, v1 = 0, v2 = 0, v3 = 0, n, a[50];
	printf("please input the number of electorate:\n");
	scanf("%d", &n); 											/*输入参加选举的人数*/
	printf("please input 1or2or3\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);										/*输入每个人所选的人*/
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] == 1)
		{
			v1++;											/*统计1号候选人的票数*/
		}
		else if (a[i] == 2)
		{
			v2++;											/*统计2号候选人的票数*/
		}
		else if (a[i] == 3)
		{
			v3++;											/*统计三号候选人的票数*/
		}
		else
		{
			v0++;											/*统计无效票数*/
		}
	}
	printf("The Result:\n");
	printf("candidate1:%d\ncandidate2:%d\ncandidate3:%d\nonuser:%d\n",v1,v2,v3,v0); 	/*将统计的结果输出*/
	return 0;
}
