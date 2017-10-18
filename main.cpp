#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct edge
{
    int src,des,weight;
    bool operator <(const edge &b) const
    {
        return weight>b.weight;
    }
};
struct graph
{
    int v;
    priority_queue<edge> me;
};
graph* creatG(int v)
{
    graph *ret=new graph;
    ret->v=v;
    return ret;
}
void addEdge(graph *lock,char unlock1[],char unlock2[],int u,int v)
{
    int sum(0);
    for(int i=0;i<4;i++)
    {
        int r=abs(unlock1[i]-unlock2[i]);
        sum+=min(10-r,r);
    }
    edge p;
    p.des=u;
    p.src=v;
    p.weight=sum;
    lock->me.push(p);
}
int parent[505];
int f(int a)
{
    while(a!=parent[a])
    {
        a=parent[a];
    }
    return a;
}
void uni(int a,int b)
{
    a=f(a);
    b=f(b);
    parent[a]=b;
}
int kruskal(graph *lock)
{
    int cost(0);
    while(!lock->me.empty())
    {
        int w=lock->me.top().weight;
        int a=lock->me.top().src;
        int b=lock->me.top().des;
        lock->me.pop();
        if(f(a)!=f(b))
        {
            uni(a,b);
            cost+=w;
        }
    }
    return cost;
}
int main()
{
    char num[505][4];
    int t,n,start;
    cin>>t;
    while(t--)
    {
        cin>>n;
        start=1e9;
        graph *lock=creatG(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            cin>>num[i];
            int sum(0);
            for(int j=0;j<4;j++)
            {
                sum+=min(num[i][j]-'0','9'-num[i][j]+1);
            }
            for(int j=0;j<i;j++)
            {
                addEdge(lock,num[j],num[i],i,j);
            }
            start=min(start,sum);
        }
        cout<<kruskal(lock)+start<<endl;
        delete lock;
    }
    return 0;
}
