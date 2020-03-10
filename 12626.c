#include<stdio.h>

int main()
{
	int M='M'-'A',A='A'-'A',R='R'-'A',G='G'-'A',I='I'-'A',T='T'-'A';
	int kase;
	scanf("%d\n",&kase);
	char buf[650];
	while(kase--)
	{
		fgets(buf,650,stdin);
		int word[26] = {0};
		int i=0;
		for(i=0;buf[i]!='\n';i++)
		{
			word[buf[i]-'A']++;
		}
		int ans = word[M];
		if(ans > word[A]/3)
			ans = word[A]/3;
		if(ans > word[R]/2)
			ans = word[R]/2;
		if(ans > word[G])
			ans = word[G];
		if(ans > word[I])
			ans = word[I];
		if(ans > word[T])
			ans = word[T];
		printf("%d\n",ans);
	}
	return 0;
}
