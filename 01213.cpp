#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1125][15];
vector<ll> prime;
int main()
{
    bool visit[1125];
    memset(visit,1,sizeof(visit));
    visit[0]=visit[0]=false;
    for(int i=2;i<1125;i++)
    {
        if(visit[i])
        {
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<1125;j++)
        {
            visit[i*prime[j]]=false;
            if(i%prime[j]==0)
                break;
        }
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<prime.size();i++)
    {
        for(int j=1120;j>=prime[i];j--)
        {
            for(int k=14;k>=1;k--)
            {
                dp[j][k] += dp[j-prime[i]][k-1];
            }
        }
    }

    ll n,k;
    while(scanf("%lld%lld",&n,&k))
    {
        if(n==0&&k==0)
            break;
        printf("%lld\n",dp[n][k]);
    }
    return 0;
}
