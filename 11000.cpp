#include <cstdio>
#define ll long long
using namespace std;

int main()
{
    int n;
    ll male[60];
    male[0]=0;
    male[1]=1;
    //m(n)=m(n-1)+m(n-2)+1
    for(int i=2;i<60;i++)
    {
        male[i]=male[i-1]+male[i-2]+1LL;
    }
    while(scanf("%d",&n)&&n!=-1)
    {
        //total is m[n]+m[n-1]+1 = m[n+1]
        printf("%lld %lld\n",male[n],male[n+1]);
    }
    return 0;
}
