#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct edge
{
    int x,y,w;
    bool operator <(const edge &b) const{return b.w>w;}
};
int f(int *parent,int u)
{
    while(parent[u]!=-1)
    {
        u=parent[u];
    }
    return u;
}
bool uni(int a,int b,int *parent,int *rak)
{
    a=f(parent,a);
    b=f(parent,b);
    if(a==b)
        return false;
    if(rak[a]>rak[b])
    {
        parent[b]=a;
        rak[a]+=rak[b];
    }
    else
    {
        parent[a]=b;
        rak[b]+=rak[a];
    }
    return true;
}

int main()
{
    int m,n,*parent,*rak,orig,tmp;
    edge input;
    vector<edge> graph;
    while(cin>>m>>n&&(n||m))
    {
        orig=0;
        tmp=0;
        parent=new int[m];
        rak=new int[m];
        fill_n(parent,m,-1);
        fill_n(rak,m,1);
        for(int i=0;i<n;i++)
        {
            cin>>input.x>>input.y>>input.w;
            orig+=input.w;
            graph.push_back(input);
        }
        sort(graph.begin(),graph.end());
        for(int i=0;i<n;i++)
        {
            if(uni(graph[i].x,graph[i].y,parent,rak))
            {
                orig-=graph[i].w;
                tmp++;
            }
            if(tmp>=m-1)
                break;
        }
        graph.clear();
        cout<<orig<<endl;
        delete []parent;
        delete []rak;
    }
    return 0;
}
