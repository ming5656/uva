#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

int cnt[26],ans;
bool st[30][30];
queue<int> arq;

void init(char *start)
{
	ans = 0;
	while(!arq.empty())
	{
		arq.pop();
	}
	memset(st,0,sizeof(bool) * 30 *30);
	memset(cnt,0,sizeof(int) * 26);
	int len = strlen(start)-1;
	for(int i=0;i<len;i++)
	{
		int c1 = start[i] - 'A';
		arq.push(c1);
		cnt[c1] = 3;
		//printf("%d\n",c1);
	}
}

int bfs()
{
	int ny = arq.size();
	while(!arq.empty())
	{
		int p = arq.front();
		arq.pop();
		for(int i=0;i<26;i++)
		{
			if(cnt[i]<3 && st[p][i])
			{
				cnt[i]++;
				if(cnt[i]==3)
				{
					arq.push(i);
				}
			}
		}
		ny--;
		if(!ny)
		{
			ans++;
			ny = arq.size();
		}
	}
	int ret = 0;
	for(int i=0;i<26;i++)
	{
		if(cnt[i]==3)
		{
			ret += 1;
		}
	}
	return ret;
}
int main()
{
	int n,m;
	char start[30],con[5];
	while(scanf("%d",&n)!=EOF)
	{
	//	ans = 0;
		scanf("%d",&m);
		fgets(start,30,stdin);
		fgets(start,30,stdin);
		//printf("%s",start);
		init(start);
		for(int i=0;i<m;i++)
		{
			fgets(con,5,stdin);
			int p1 = con[0]-'A',p2 = con[1]-'A';
			st[p1][p2] = st[p2][p1] = true;
		}
		if(bfs()==n)
		{
			printf("WAKE UP IN, %d, YEARS\n",ans-1);
		}
		else
		{
			printf("THIS BRAIN NEVER WAKES UP\n");
		}
		
	}
	return 0;
}
