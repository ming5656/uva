#include <iostream>
#include <algorithm>

using namespace std;

void mypower(long long a[][45],long long n,long long p,long long l)
{
    long long cur[45][45],ans[45][45],nxt[45][45];
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<n;j++)
        {
            cur[i][j]=a[i][j];
        }
        fill_n(ans[i],45,0);
        ans[i][i]=1;
    }
    l=l-n+1;
    while(l)
    {
        if(l&1)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    nxt[i][j]=0;
                    for(int k=0; k<n; k++)
                    {
                        nxt[i][j]=(nxt[i][j]+(ans[i][k]*cur[k][j])%p)%p;
                    }
                }
            }
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    ans[i][j]=nxt[i][j];
                }
            }
        }
        l=l>>1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                nxt[i][j]=0;
                for(int k=0; k<n; k++)
                {
                    nxt[i][j]=(nxt[i][j]+((cur[i][k]*cur[k][j])%p))%p;
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cur[i][j]=nxt[i][j];
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            a[i][j]=ans[i][j];
        }
    }
}
int main()
{
    long long d,n,m,matrix[45][45],f[45];
    while(cin>>d>>n>>m)
    {
        if(!d&&!n&&!m)
            break;
        for(int i=0; i<d; i++)
        {
            fill_n(matrix[i],45,0);
            cin>>matrix[0][i];
            matrix[0][i]%=m;
        }
        for(int i=0;i<d-1;i++)
            matrix[i+1][i]=1;
        for(int i=0; i<d; i++)
        {
            cin>>f[i];
            f[i]%=m;
        }
        if(n<=2)
        {
            cout<<f[n-1]<<endl;
            continue;
        }
        long long ans(0);
        mypower(matrix,d,m,n-1);
        for(int i=0;i<d;i++)
        {
            ans=(ans+(f[d-i-1]*matrix[0][i])%m)%m;
        }
        cout<<ans<<endl;
    }
    return 0;
}
