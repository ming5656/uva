#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    bool isJolly,jolly[3005];
    int pre,now,n;
    while(cin>>n)
    {
        fill_n(jolly,3005,false);
        cin>>pre;
        isJolly=true;
        for(int i=1;i<n;i++)
        {
            cin>>now;
            int v=abs(now-pre);
            if(v<1||v>=n||jolly[v])
            {
                isJolly=false;
                cout<<"Not jolly"<<endl;
                for(int j=i+1;j<n;j++)
                    cin>>now;
                break;
            }
            pre=now;
            jolly[v]=true;
        }
        if(isJolly)
            cout<<"Jolly"<<endl;
    }
    return 0;
}
