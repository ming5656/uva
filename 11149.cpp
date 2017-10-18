#include <iostream>
#include <algorithm>

using namespace std;

class matrix
{
public:
    matrix(int num);
    matrix(const matrix &d);
    friend istream& operator >>(istream& a,matrix& b);
    friend ostream& operator <<(ostream& a,matrix& b);
    friend const matrix operator *(const matrix& a,const matrix& b);
    friend const matrix operator +(const matrix& a,const matrix& b);
    friend const matrix power(const matrix& a,int k);
    matrix& operator =(const matrix& r);
    ~matrix();
private:
    long int **m;
    int n;
};
const matrix solve(matrix& base,int k,int num)
{
    matrix e(num),x(base);
    if(k==0)
    {
        return e;
    }
    else if(k==1)
    {
        return base;
    }
    matrix p(num),q(num),t(num);
    p=e+power(base,k/2);
    q=solve(base,k/2,num);
    t=power(base,k);
    if(k%2==0)
        return p*q;
    else
        return (p*q)+t;
}
int main()
{
    int n,k;
    while(cin>>n>>k&&n)
    {
        matrix input(n);
        cin>>input;
        matrix ans(n);
        ans=solve(input,k,n);
        cout<<ans<<endl;
    }
    return 0;
}
matrix::matrix(int num)
{
    m=new long int *[num];
    for(int i=0;i<num;i++)
    {
        m[i]=new long int[num];
        fill_n(m[i],num,0);
        m[i][i]=1;
    }
    n=num;
}
 istream& operator >>(istream& a,matrix& b)
{
    long int y;
    for(int i=0;i<b.n;i++)
    {
        for(int j=0;j<b.n;j++)
        {
            a>>y;
            b.m[i][j]=y%10;
        }
    }
    return a;
}
ostream& operator <<(ostream& a,matrix& b)
{
    for(int i=0;i<b.n;i++)
    {
        for(int j=0;j<b.n-1;j++)
        {
            a<<b.m[i][j]<<" ";
        }
        a<<(b.m[i][b.n-1])%10<<endl;
    }
    return a;
}
const matrix operator *(const matrix& a,const matrix& b)
{
    matrix c(a.n);
    for(int i=0;i<a.n;i++)
    {
        for(int j=0;j<a.n;j++)
        {
            c.m[i][j]=0;
            for(int k=0;k<a.n;k++)
            {
                c.m[i][j]=((a.m[i][k]*b.m[k][j])%10+c.m[i][j])%10;
            }
        }
    }
    return c;
}
const matrix operator +(const matrix& a,const matrix& b)
{
    matrix c(a.n);
    for(int i=0;i<a.n;i++)
    {
        for(int j=0;j<a.n;j++)
        {
            c.m[i][j]=(a.m[i][j]+b.m[i][j])%10;
        }
    }
    return c;
}
matrix::matrix(const matrix& d)
{
    n=d.n;
    m=new long int*[n];
    for(int i=0;i<n;i++)
    {
        m[i]=new long int[n];
    }
    for(int i=0;i<d.n;i++)
    {
        for(int j=0;j<d.n;j++)
        {
            m[i][j]=d.m[i][j];
        }
    }
}
const matrix power(const matrix& a,int k)
{
    matrix cur(a),res(a.n);
    while(k)
    {
        if(k&1)
        {
            res=res*cur;
        }
        k=k>>1;
        cur=cur*cur;
    }
    return res;
}
matrix::~matrix()
{
    for(int i=0;i<n;i++)
        delete []m[i];
    delete m;
}
matrix& matrix::operator =(const matrix& r)
{
    for(int i=0;i<r.n;i++)
    {
        for(int j=0;j<r.n;j++)
        {
            m[i][j]=r.m[i][j];
        }
    }
    n=r.n;
    return *this;
}
