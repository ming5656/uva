#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int n,t;
    char ans[4096];
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==0||n==1)
        {
            cout<<n<<endl;
            continue;
        }
        int index(0);
        for(int i=9;i>1;i--)
        {
            while(n%i==0)
            {
                ans[index++]='0'+i;
                n/=i;
            }
        }
        if(n>9)
        {
            cout<<"-1"<<endl;
            continue;
        }
        reverse(ans,ans+index);
        ans[index]='\0';
        cout<<ans<<endl;
    }
    return 0;
}
