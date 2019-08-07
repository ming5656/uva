#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int dp1[12005],dp2[12005];
	int m,n,c,p,i,j;
	while(scanf("%d%d",&m,&n)!=EOF)
	{	
		memset(dp1,0,sizeof(int)*12005);
		memset(dp2,0,sizeof(int)*12005);
		dp1[0] = dp2[0] = 1;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&p,&c);
			for(j=m;j>=p;j--)
			{
				if(dp1[j-p] && dp1[j] < dp1[j-p] + c)
				{
					dp1[j] = dp1[j-p] +c;
				}	
			}
			if(m <=1800)
				continue;
			for(j=m+200;j>=p;j--)
			{
				if(dp2[j-p] && dp2[j]< dp2[j-p] + c)
				{
					dp2[j] = dp2[j-p] +c;
				}
			}
		}
		int ans = 0;
		for(i=0;i<=m;i++)
		{
			ans = ans > dp1[i] ? ans:dp1[i];
		}
		if(m>1800)
		{
			for(i=2001;i<=m+200;i++)
			{
				ans = ans > dp2[i] ?ans:dp2[i];
			}
		}
		printf("%d\n",ans-1);

	}
	return 0;
}
