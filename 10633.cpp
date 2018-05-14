#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //freopen("in.txt", "rt", stdin);
    //freopen("out.txt", "w+t", stdout);
    ll input;
    while(scanf("%lld",&input)&&input)
    {
        int cnt = 0;
        for(int i =9 ;i>=0;i--)
        {
            if((input-i) % 9 == 0)
            {
                ll m = (input-i)/9;
                if(cnt++)
                    putchar(' ');
                printf("%lld",input+m);
            }
        }
        printf("\n");
    }
    return 0;
}
