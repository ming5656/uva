#include <bits/stdc++.h>

using namespace std;

int t,n,k;
vector<int> e[1005];
int dfs(int last,int cur)
{
    if(e[cur].size() < k)
        return 1;
    int ret = 1,num = e[cur].size();
    vector<int> child;
    for(auto v:e[cur])
    {
        if(v == last)
        {
            num--;
            if(num < k)
                return 1;
        }
        else
        {
            int p =dfs(cur,v);
            child.push_back(p);
        }
    }
    sort(child.begin(),child.end(),greater<int>());
    for(int i=0;i< k ;i++)
    {
        ret += child[i];
    }
    return ret;
}
int main()
{
    int u,v;
    scanf("%d",&t);
    for(int kase =1 ;kase <=t; kase++)
    {
        scanf("%d%d",&n,&k);
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        printf("Case %d: %d\n",kase,dfs(-1,1));
        for(int i=1;i<=n;i++)
            e[i].clear();
    }
    return 0;
}
