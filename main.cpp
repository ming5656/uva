#include <bits/stdc++.h>

using namespace std;

int main()
{
    char input[1024];
    while(cin>>input)
    {
        int len=strlen(input),num(0);
        bool ans(true);
        for(int i=len-1;i>=0;i--)
        {
            if(input[i]>='p'&&input[i]<='z')
            {
                num++;
            }
            else if(input[i]=='N')
            {
                if(!num)
                {
                    ans=false;
                    break;
                }
            }
            else if(input[i]=='I'||input[i]=='C'||input[i]=='D'||input[i]=='E')
            {
                if(num<2)
                {
                    ans=false;
                    break;
                }
                num--;
            }
            else
            {
                ans=false;
                break;
            }
        }
        if(ans&&num==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
