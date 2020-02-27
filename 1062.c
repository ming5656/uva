#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int lis(char *ships)
{
	int n = strlen(ships);
	n--;
	if(!n)
		return 0;
	int i,j,ans = 0;
	int l[1005];
	for(i=0;i<n;i++)
	{
		l[i] = 1;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ships[i] < ships[j])
			{
				if(l[i] +1 > l[j])
				{
					l[j] = l[i]+1;
				}
			}
		}
	}
	for(i = 0; i<n ;i++)
	{
		if(ans < l[i])
			ans = l[i];
	}
	return ans;
}
int main()
{
	char ships[1005];
	int kase = 1;
	while(fgets(ships,1005,stdin)!=NULL)
	{
		if(strcmp(ships,"end\n")==0)
		{
			break;	
		}
		printf("Case %d: %d\n",kase++,lis(ships));
	}
	return 0;
}
