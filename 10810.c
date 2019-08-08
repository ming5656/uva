#include<stdio.h>
#include<stdlib.h>
int num[500005];
long int ans;

void merge(int l1,int l2,int r1,int r2)
{
	int i,j,bufcnt=0;
	int *buf = (int *)malloc(sizeof(int) * (r2-l1+1));
	for(i=l1,j=r1;i<=l2 && j<=r2;)
	{
		if(num[i] > num[j])
		{
			buf[bufcnt] = num[j];
			ans += (j+l2-r1-l1+1 - bufcnt);
			bufcnt++;
			j++;
		}
		else
		{
			buf[bufcnt++] = num[i++];
		}
	}
	for(;i<=l2;i++)
	{
		buf[bufcnt++] = num[i];
	}
	for(;j<=r2;j++)
	{
		buf[bufcnt++] = num[j];
	}
	for(i=l1;i<=r2;i++)
	{
		num[i] = buf[i-l1];
	}
	free(buf);
}

void mergesort(int l,int r)
{
	if(l>=r)
	{
		return;	
	}
	int m = (l+r)/2;
	mergesort(l,m);
	mergesort(m+1,r);
	merge(l,m,m+1,r);
}

int main()
{

	int n,i;
	while(scanf("%d",&n) && n)
	{
		ans = 0;
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		mergesort(0,n-1);
		printf("%ld\n",ans);
	}
	return 0;
}
