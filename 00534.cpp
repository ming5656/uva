#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <iomanip>
using namespace std;
float dijsktra(float stone[][205],int n)
{
    bool *visit=new bool[n];
    float *dis=new float[n];
    memset(visit,false,sizeof(bool)*n);
    for(int i=0;i<n;i++)
    {
        dis[i]=stone[0][i];
    }
    visit[0]=true;
    for(int i=0;i<n-1;i++)
    {
        int minN(3000000.0),w(-1);
        for(int j=1;j<n;j++)
        {
            if(!visit[j]&&minN>dis[j])
            {
                w=j;
                minN=dis[j];
            }
        }
        visit[w]=true;
        for(int j=0;j<n;j++)
        {
            if(!visit[j])
            {
                if(dis[j]>max(dis[w],stone[w][j]))
                {
                    dis[j]=max(dis[w],stone[w][j]);
                }
            }
        }
    }
    float ans=dis[1];
    delete []dis;
    delete []visit;
    return ans;
}
int main()
{
    float stone[205][205],x[205],y[205];
    int times,kase(0);
    while(cin>>times&&times)
    {
        for(int i=0;i<times;i++)
        {
            cin>>x[i]>>y[i];
            stone[i][i]=0.0;
            for(int j=0;j<i;j++)
            {
                float disx=x[i]-x[j];
                float disy=y[i]-y[j];
                stone[i][j]=stone[j][i]=sqrt(disx*disx+disy*disy);
            }
        }
        cout<<"Scenario #"<<++kase<<endl;
        cout<<"Frog Distance = "<<fixed<<setprecision(3)<<dijsktra(stone,times)<<endl<<endl;
    }
    return 0;
}
