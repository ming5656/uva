#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

vector<int> prime;
bool sieve[10005];

void linear_sieve()
{
	memset(sieve,0,10005);
	sieve[0] = sieve[1] = true;
	for(int i=2;i<10005;i++)
	{
		if(!sieve[i])
		{
			prime.push_back(i);
		}
		for(int j=0;j<prime.size() && i *prime[j] <10005;j++)
		{
			sieve[i*prime[j]] =true;
			if(i % prime[j]==0)
				break;
		}
	}	
}
int main()
{
	int p,x,n,m;
	scanf("%d",&m);
	linear_sieve();
	while(m--)
	{
		scanf("%d",&n);
		int ans=0,diff=0;
		for(int i=0;i<prime.size() && prime[i]<n;i++)
		{
			p = n % prime[i];	
			if(p > diff)
			{
				diff = p;
				ans = prime[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
