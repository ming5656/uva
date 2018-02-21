#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct node
{
    int from,to,value;
    int next;
};
int e,head[105],pre[105],record[105];
struct node edge[30005];
char output[10];
void addEdge(int x,int y,int v)
{
    edge[e].from=x;
    edge[e].to=y;
    edge[e].value=v;
    edge[e].next=head[x];
    head[x]=e++;
    edge[e].from=y;
    edge[e].to=x;
    edge[e].value=0;
    edge[e].next=head[y];
    head[y]=e++;
}
bool bfs()
{
    bool visit[40];
    memset(visit,false,sizeof(visit));
    queue<int> q;
    q.push(0);
    visit[0]=true;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=head[x]; i!=-1; i=edge[i].next)
        {
            int y=edge[i].to;
            if(!visit[y]&&edge[i].value>0)
            {
                pre[y]=x;
                record[y]=i;
                visit[y]=true;
                q.push(y);
            }
        }
        if(visit[37])
            return true;
    }
    return false;
}
int maxFlow()
{
    int ans(0),x;
    while(bfs())
    {
        ans++;
        for(x=37; x!=0; x=pre[x])
        {
            int flow=record[x];
            edge[flow].value-=1;
            edge[flow^1].value+=1;
        }
    }
    return ans;
}
int main()
{
    char input[1024];
    int num,totalflow(0);
    memset(head,-1,sizeof(head));
    e=0;
    while(cin.getline(input,1024))
    {
        if(strcmp(input,"")==0)
        {
            for(int i=27; i<37; i++)
                addEdge(i,37,1);
            if(maxFlow()!=totalflow)
            {
                cout<<"!"<<endl;
            }
            else
            {
                memset(output,'_',sizeof(output));
                for(int j=1; j<=26; j++)
                {
                    for(int k=head[j]; k!=-1; k=edge[k].next)
                    {
                        if(edge[k].value==0)
                        {
                            output[edge[k].to-27]=j-1+'A';
                        }
                    }
                }
                cout<<output<<endl;
            }
            memset(head,-1,sizeof(head));
            totalflow=e=0;
            continue;
        }
        int x=input[0]-'@';
        int y=input[1]-'0';
        totalflow+=y;
        int z=3;
        while(input[z]!=';')
        {
            addEdge(x,input[z]-'0'+27,1);
            z++;
        }
        addEdge(0,x,y);
    }

    for(int i=27; i<37; i++)
        addEdge(i,37,1);
    if(maxFlow()!=totalflow)
    {
        cout<<"!"<<endl;
    }
    else
    {
        memset(output,'_',sizeof(output));
        for(int j=1; j<=26; j++)
        {
            for(int k=head[j]; k!=-1; k=edge[k].next)
            {
                if(edge[k].value==0)
                {
                    output[edge[k].to-27]=j-1+'A';
                }
            }
        }
        cout<<output<<endl;
    }
    return 0;
}
