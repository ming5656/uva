#include <iostream>
#include <cstdio>

using namespace std;
void mul(long long x[][2],long long y[][2],long long p)
{
    long long z[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            z[i][j]=0;
            for(int k=0;k<2;k++)
            {
                z[i][j]=(z[i][j]+(x[i][k]*y[k][j])%p)%p;
            }
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            x[i][j]=z[i][j];
        }
    }
}
void power(long long x[][2],long long k,long long p)
{
    long long y[2][2],z[2][2];
    y[0][0]=y[1][1]=1;
    y[0][1]=y[1][0]=0;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            z[i][j]=x[i][j];
        }
    }
    while(k>0)
    {
        if(k&1)
        {
            mul(y,z,p);
        }
        k=k>>1;
        mul(z,z,p);
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            x[i][j]=y[i][j];
        }
    }
}
int main()
{
    long long n,m,p,matrix[2][2],a,b;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n>>m;
        p=1;
        for(int j=0;j<m;j++)
        {
            p*=10;
        }
        matrix[1][0]=matrix[0][0]=matrix[0][1]=1;
        matrix[1][1]=0;
        power(matrix,n-1,p);
        cout<<(((matrix[0][1]*a)%p)+((matrix[0][0]*b)%p))%p<<endl;
    }
    return 0;
}
