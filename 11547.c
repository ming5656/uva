#include<stdio.h>

int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		m = (n * 567 / 9 + 7492) * 235 / 47 -498;
		if(m < 10 && m > -10)
			printf("0\n");
		else
		{	
			m = (m < 0)?-1*m:m;
			
			printf("%d\n",(m/10)%10);
		}
	}
	return 0;
}
