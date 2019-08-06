#include<stdio.h>

int main()
{
	int num[4],ans;
	while(scanf("%d%d%d%d",&num[0],&num[1],&num[2],&num[3])!=EOF)
	{
		if(!(num[0]||num[1]||num[2]||num[3]))
			break;
		ans = 1080;
		ans += ((num[0]-num[1])+40)%40*9;
		ans += ((num[2]-num[1])+40)%40*9;
		ans += ((num[2]-num[3])+40)%40*9;
		printf("%d\n",ans);
	}
	return 0;
}
