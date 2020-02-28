#include<cstring>
#include<cstdio>
#include<map>
#include<string>
#include<iostream>

using namespace std;

int main()
{
	char buf[1000000];
	int n;
	map<string,int> password;
	map<string,int>::iterator it;
	while(scanf("%d%s",&n,buf)!=EOF)
	{
	//	cout<<n<<endl;
		password.clear();
		int len = strlen(buf),num=0;
		char cbuf[n+1];
		string ans;
		for(int i=0; i <= len - n; i++)
		{
			strncpy(cbuf,buf+i,n);
			cbuf[n] = '\0';
			it = password.find(string(cbuf));
			if(it != password.end())
				password[string(cbuf)]++;
			else
				password.insert(pair<string, int>(string(cbuf),1));
		}
		for(it = password.begin(); it != password.end(); it++)
		{
			if(num < it->second)
			{
				ans = it->first;	
				num = it->second;
			}
		}
		cout<< ans << endl;
	}
	return 0;
}
