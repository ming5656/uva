
#include<stdio.h>

int main()
{
	unsigned long long a;
	while(scanf("%llu",&a)!=EOF)
	{
		printf("%llu\n", (3 * (a+1) * (a+1))/2 - 9);
	}
	return 0;
}
