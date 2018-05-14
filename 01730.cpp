#include <cstdio>
#define ll long long
using namespace std;

int main()
{
    ll n;
    while(scanf("%lld",&n)!=EOF && n)
    {
        ll ans(-1),times,r,l(1);
        while(l<=n)
        {
            times = n/l;
            r = n/times;
            ans += (times*((l+r)*(r-l+1)/2));
            l = r+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
