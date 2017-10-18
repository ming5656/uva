#include <iostream>

using namespace std;

void mulMatrix(long long a[][2],long long b[][2],long long p)
{
    long long c[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            c[i][j]=0;
            for(int k=0;k<2;k++)
            {
                c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%p)%p;
            }
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            a[i][j]=c[i][j];
    }
}
long long fib(long long k,long long p)
{
    long long matrix[2][2],ans[2][2];
    ans[0][0]=ans[0][1]=ans[1][0]=matrix[0][0]=matrix[0][1]=matrix[1][0]=1;
    matrix[1][1]=ans[1][1]=0;
    while(k)
    {
        if(k&1)
        {
            mulMatrix(ans,matrix,p);
        }
        k>>=1;
        mulMatrix(matrix,matrix,p);
    }
    return ans[1][0];
}
int main()
{
    long long n,b;
    int kase(0);
    while(cin>>n>>b)
    {
        if(!n&&!b)
            break;
        long long f=fib(n,b);
        cout<<"Case "<<++kase<<": "<<n<<" "<<b<<" "<<(f*2-1+b)%b<<endl;
    }
    return 0;
}
