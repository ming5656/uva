#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct edge
{
    int s,e,w;
    bool operator <(const edge& b)const {return b.w>w;}
};
int f(int a,int *parent)
{
    while(parent[a]!=-1)
    {
        a=parent[a];
    }
    return a;
}
bool uni(int a,int b,int *parent,int *ran)
{
    a=f(a,parent);
    b=f(b,parent);
    if(a==b)
        return false;
    if(ran[a]>ran[b])
    {
        parent[b]=a;
        ran[a]+=ran[b];
    }
    else
    {
        parent[a]=b;
        ran[b]+=ran[a];
    }
    return true;
}
int main()
{
    int s,c,w,*parent,*ran;
    map<string,int> graph;
    string name,station1,station2;
    vector<edge> network;
    while(cin>>s>>c&&(s||c))
    {
        parent=new int[s];
        ran=new int[s];
        fill_n(parent,s,-1);
        fill_n(ran,s,1);
        for(int i=0;i<s;i++)
        {
            cin>>name;
            graph.insert(pair<string,int>(name,i));
        }
        for(int i=0;i<c;i++)
        {
            cin>>station1>>station2>>w;
            int a=graph[station1],b=graph[station2];
            edge net;
            net.s=a;
            net.e=b;
            net.w=w;
            network.push_back(net);
        }
        sort(network.begin(),network.end());
        int ans(0);
        for(int i=0;i<c;i++)
        {
            if(uni(network[i].s,network[i].e,parent,ran))
            {
                ans+=network[i].w;
            }
        }
        cin>>name;
        int comb(0);
        for(int i=0;i<s;i++)
        {
            if(parent[i]==-1)
            {
                comb++;
                if(comb>1)
                    break;
            }
        }
        network.clear();
        if(comb>1)
        {
            cout<<"Impossible"<<endl;
        }
        else
            cout<<ans<<endl;
        graph.clear();
        delete []parent;
        delete []ran;
    }
    return 0;
}
