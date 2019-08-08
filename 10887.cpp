#include<cstdio>
#include<set>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
	int t,m,n;
	scanf("%d",&t);
	set<string> concat;
	char f[1505][15],s[15],str[40];
	for(int kase=1;kase<=t;kase++)
	{
		concat.clear();
		scanf("%d %d",&m,&n);
		fgets(s,15,stdin);
		for(int i=0;i<m;i++)
		{
			fgets(f[i],15,stdin);
			f[i][strlen(f[i])-1]= '\0';
		}
		for(int i=0;i<n;i++)
		{
			fgets(s,15,stdin);
			s[strlen(s)-1] = '\0';
			for(int j=0;j<m;j++)
			{
				strcpy(str,f[j]);
				strcat(str,s);
				concat.insert(string(str));
			}
		}
		printf("Case %d: %ld\n",kase,concat.size());
	}
	return 0;
}
