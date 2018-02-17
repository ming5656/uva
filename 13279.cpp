#include <bits/stdc++.h>

using namespace std;
#define pn 5000001
#define p  100000007
#define ll long long
vector<ll> prime;

void sieve()
{
    vector<bool> isPrime(pn+1,true);
    isPrime[0] = isPrime[1] =false;
    for(int i=2; i <= pn ;i++)
    {
        if(isPrime[i] ==true)
        {
            prime.push_back(i);
        }
        for(int j=0; i * prime[j]<= pn;j++)
        {
            isPrime[i*prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}
ll divisor(ll n)
{
    ll ret =1;
    for(int i=0;prime[i] <= n && i < prime.size();i++)
    {
        ll ex = 0;
        ll num = prime[i];
        ll nn =n;
        while(num<=n)
        {
            ll np = nn/prime[i];
            ex += ((((np-1)*np/2)%p * num ) %p +((n%num+1) *np)%p) %p;
            ex %= p;
            nn /= prime[i];
            num =num *prime[i];
        }
        ret = (ret * (ex +1 )) %p;
    }
    return ret;
}
int main()
{
    //freopen("in.txt", "rt", stdin);
//freopen("out.txt", "w+t", stdout);

    ll n;
    sieve();
    while(scanf("%lld",&n) && n)
    {
        cout<<divisor(n)<<endl;
    }
    return 0;
}

