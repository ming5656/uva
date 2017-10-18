#include <bits/stdc++.h>
using namespace std;

int building[105][105];
void dijsktra(int s,int n,int time[])
{
    vector<int> dis(n,1e9);
    vector<bool> visit(n,false);
    dis[s]=0;
    int ans(0);
    for(int j=0; j<n; j++)
    {
        int minv=1e9,u=-1;
        for(int i=0; i<n; i++)
        {
            if(dis[i]<minv&&!visit[i])
            {
                minv=dis[i];
                u=i;
            }
        }
        if(u==-1)
            break;
        visit[u]=true;
        for(int i=0; i<n; i++)
        {
            if(!visit[i]&&building[u][i]&&dis[i]>dis[u]+building[u][i])
                dis[i]=dis[u]+building[u][i];
        }
    }
    for(int i=0;i<n;i++)
        time[i]=dis[i];
}
int main()
{
    int t,n,s,e,r,st[105],et[105],kase(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>r;
        memset(building,0,sizeof(building));
        for(int i=0; i<r; i++)
        {
            cin>>s>>e;
            building[s][e]=building[e][s]=1;
        }
        cin>>s>>e;
        dijsktra(s,n,st);
        dijsktra(e,n,et);
        int ans(0);
        for(int i=0;i<n;i++)
        {
            ans=max(ans,st[i]+et[i]);
        }
        cout<<"Case "<<++kase<<": ";
        cout<<ans<<endl;
    }
    return 0;
}
