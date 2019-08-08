#include<stdio.h>

int main()
{
	int i;
	char buf[20];
	while(fgets(buf,20,stdin)!=NULL)
	{
		if(buf[0]=='_')
			continue;
		char wd = 0;
		int p = 128;
		for(i=0;i<10;i++)
		{
			if(buf[i]=='|' || buf[i]=='.')
			{
				continue;
			}
			else
			{
				if(buf[i]=='o')
				{
					wd += p;
				}
				p /= 2;
			}
		}
		printf("%c",wd);
	}
	return 0;
}
