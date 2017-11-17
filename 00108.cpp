#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int temp[101],matrix[105][105],n;
int kadane()
{
    int sum(0),s=-1,m(-12800);
    for(int i=0;i<n;i++)
    {
        sum+=temp[i];
        m=max(sum,m);
        if(sum<0)
        {
            sum=0;
            s=i+1;
        }
    }
    return m;
}
void solve()
{


    int sum = -99999999;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    for(int l=0;l<n;l++)
    {
        fill_n(temp,n,0);
        for(int r=l;r<n;r++)
        {
            for(int row=0;row<n;row++)
            {
                temp[row]+=matrix[r][row];
            }
            sum = max(sum,kadane());
        }
    }
    printf("%d\n",sum);
}
int main()
{
    while(cin>>n)
    {
        solve();
    }
    return 0;
}
