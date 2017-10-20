#include <iostream>
#include <cstring>
using namespace std;

#define num 305
#define len 2005
//catalan number x n!
int main()
{
    int c[num][len],last,n;
    memset(c,0,sizeof(c));
    c[1][0]=1;
    last=0;
    for(int i=2;i<num;i++)
    {
        for(int j=0;j<len;j++)
        {
            int sum=(last+c[i-1][j]*(4*i-2)*i);
            c[i][j]=sum%10;
            last=sum/10;
        }
        for(int j=len-1;j>=0;j--)
        {
            c[i][j-1]+=(c[i][j]%(i+1))*10;
            c[i][j]/=(i+1);
        }
    }
    while(cin>>n&&n)
    {
        int i;
        for(i=len-1;!c[n][i];i--);
        for(int j=i;j>=0;j--)
            cout<<c[n][j];
        cout<<endl;
    }
    return 0;
}
