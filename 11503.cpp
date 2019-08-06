#include <iostream>
#include <string>
#include <map>
#include<cstdio>

using namespace std;

struct fset{
	int pt;
	int num;
};

fset g[100005];

void init(int f)
{
	for(int i=0;i<f;i++)
	{
		g[i].pt = i;
		g[i].num = 1;
	}
}

int findroot(int r)
{
	if(r==g[r].pt)
		return r;
	return findroot(g[r].pt);
}

int uni(int s1,int s2)
{
	int r1 = findroot(s1),r2 = findroot(s2);
	if(r1==r2)
		return r1;
	if(g[r1].pt > g[r2].pt)
	{
		g[r2].pt = r1;
		g[r1].num += g[r2].num;
		return r1;
	}
	else
	{	
		g[r1].pt = r2;
		g[r2].num += g[r1].num;
		return r2;
	}
}
int main()
{
	int kase,f;
	char p1[25],p2[25];
	scanf("%d",&kase);
	map<string,int> people;
	map<string,int>::iterator iter;
	while(kase--)
	{
		int pnum(0);
		people.clear();
		scanf("%d",&f);
		init(f);
		for(int i=0;i<f;i++)
		{
			scanf("%s %s",p1,p2);
			//string str1(p1);
			//string str2(p2);
			//cout<<str1<<str2<<endl;
			iter = people.find(p1);
			int s1,s2;
			if(iter == people.end())
			{
				//cout<<"Not exist\n";
				people.insert(pair<string,int>(p1,pnum));
				s1 = pnum++;
			}
			else
			{
				//cout<<iter->first<<" "<<iter->second<<endl;
				s1 = iter->second;
			}
			iter = people.find(p2);
			if(iter == people.end())
			{
				//cout<<"Not exist\n";
				people.insert(pair<string,int>(p2,pnum));
				s2 = pnum++;
			}
			else
			{
				//cout<<iter->first<<" "<<iter->second<<endl;
				s2 = iter->second;
			}
			cout<<g[uni(s1,s2)].num<<endl;
			
			
		}
	}
	return 0;
}

