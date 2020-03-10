#include<stdio.h>

int main()
{
	int t,n,kase = 0;
	scanf("%d",&t);
	while(kase<t)
	{
		scanf("%d",&n);
		int ans = 0,c;
		while(n--)
		{
			scanf("%d",&c);
			if(ans < c)
				ans = c;
		}
		printf("Case %d: %d\n",++kase,ans);
	}
	return 0;
}
