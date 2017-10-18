#include <cstdio>
#include <cstring>
#define ll long long
#define P  1000000007
using namespace std;

ll ns(0);
ll res;
int pos[1000005],num,prime[100000];
bool isPrime[1000005];
void sieve()
{
    memset(isPrime,1,sizeof(isPrime));
    memset(pos,0,sizeof(pos));
    isPrime[0]=isPrime[1]=false;
    for(int i=2; i<1000005; i++)
    {
        if(isPrime[i])
        {
            pos[i]=ns;
            prime[ns++]=i;
            for(int j=i*2; j<1000005; j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
}
ll inverse_module(ll s)
{
    ll r=P-2,ans(1),c=s;
    while(r>0)
    {
        if(r&1)
        {
            ans=(ans*c)%P;
        }
        c=(c*c)%P;
        r>>=1;
    }
    return ans;
}

int main()
{
    int t,kase(0);
    int n;
    scanf("%d",&t);
    sieve();
    while(t--)
    {
        ll cnt[100000]= {};
        res=1;;
        scanf("%d",&n);
        ll total(0);
        while(n--)
        {
            scanf("%d",&num);
            if(num<0)
            {
                num=-num;
                int pp;
                for(int i=0; i<ns&&num>=prime[i]&&!isPrime[num]; i++)
                {
                    if(num%prime[i]==0)
                    {
                        ll d(0);
                        while(num%prime[i]==0)
                        {
                            d++;
                            num/=prime[i];
                        }
                        res=((res*((cnt[i]-d+1)%P)%P)*(inverse_module(cnt[i]+1)%P))%P;
                        cnt[i]-=d;
                    }
                }
                pp=pos[num];
                if(isPrime[num])
                {
                    res=((res*((cnt[pp])%P)%P)*(inverse_module(cnt[pp]+1)%P))%P;
                    cnt[pp]--;
                }
            }
            else
            {
                int pp;
                for(int i=0; i<ns&&num>=prime[i]&&!isPrime[num]; i++)
                {
                    if(num%prime[i]==0)
                    {
                        ll d(0);
                        while(num%prime[i]==0)
                        {
                            d++;
                            num/=prime[i];
                        }
                        res=((res*((cnt[i]+d+1)%P)%P)*((inverse_module(cnt[i]+1))%P))%P;
                        cnt[i]+=d;
                    }
                }
                pp=pos[num];
                if(isPrime[num])
                {
                    res=((res*((cnt[pp]+2)%P)%P)*(inverse_module(cnt[pp]+1)%P))%P;
                    cnt[pp]++;
                }
            }
            total+=res;
            total%=P;
        }
        printf("Case %d: %llu\n",++kase,total);
    }
    return 0;
}
