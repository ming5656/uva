#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull powerNum(ull a,ull b,ull n)
{
    ull base=a,ret=1;
    while(b>0)
    {
        if(b&1)
        {
            ret=(ret*base)%n;
        }
        b>>=1;
        base=(base*base)%n;
    }
    return ret;
}
void mulMatrix(ull a[][2],ull b[][2],ull n)
{
    ull c[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            c[i][j]=0;
            for(int k=0;k<2;k++)
            {
                c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%n)%n;
            }
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            a[i][j]=c[i][j];
        }
    }
}
ull slove(ull p,ull n)
{
    ull base[2][2]={{1,1},{1,0}},ans[2][2]={{1,0},{0,1}};
    p--;
    while(p>0)
    {
        if(p&1)
        {
            mulMatrix(ans,base,n);
        }
        p>>=1;
        mulMatrix(base,base,n);
    }
    cout<<ans[0][1]<<endl;
}
int main()
{
    freopen("in.txt","rt",stdin);
    freopen("out.txt","w+t",stdout);
    int t;
    ull a,b,n;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        if(n==1)
        {
            cout<<"0"<<endl;
            continue;
        }
        a%=n;
        ull p=powerNum(a,b,n);
        if(p==0)
            cout<<"0"<<endl;
        else if(p==1)
            cout<<"1"<<endl;
        else
            slove(p,n);
    }
    return 0;
}
