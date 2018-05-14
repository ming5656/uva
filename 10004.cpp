#include <bits/stdc++.h>

using namespace std;

struct graph
{
    vector<int> *adj;
    int len;
    graph(int n)
    {
        adj = new vector<int>[n];
        len = n;
    };
};

int color[205];

bool dfs(graph g,int v)
{
    int u;
    for(int i=0;i<g.adj[v].size();i++)
    {
        if(!color[g.adj[v][i]])
        {
            color[g.adj[v][i]] = -color[v];
            if(!dfs(g,g.adj[v][i]))
            {
                return false;
            }
        }
        else
        {
            if(color[g.adj[v][i]] == color[v])
                return false;
        }
    }
    return true;
}
int main()
{
    int n,t,l,a,b;
    while(scanf("%d",&n)&&n)
    {
        scanf("%d",&l);
        memset(color,0,sizeof(int)*205);
        graph g(n);
        for(int i=0;i<l;i++)
        {
            scanf("%d%d",&a,&b);
            g.adj[a].push_back(b);
            g.adj[b].push_back(a);
        }
        color[0] = true;
        if(!dfs(g,0))
            cout<<"NOT ";
        cout<<"BICOLORABLE."<<endl;
        delete[] g.adj;
    }


    return 0;
}
