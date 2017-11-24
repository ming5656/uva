#include <bits/stdc++.h>

using namespace std;

struct job
{
    int s,e,index;
    bool operator<(const job& b) const
    {
        if(s==b.s)
            return e>b.e;
        return s > b.s;
    }
};
bool solve(job r[],int n,int pos[])
{
    priority_queue<job> pq;
    for(int i=1;i<=n;i++)
    {
        pq.push(r[i]);
    }
    for(int i=1;i<=n;i++)
    {
        while(1)
        {
            job t = pq.top();
            if(t.s<i)
                pq.pop();
            else
                break;
            t.s = i;
            pq.push(t);
        }
        job t = pq.top();
        if(i<t.s||i>t.e)
            return false;
        pq.pop();
        pos[t.index] = i;
    }
    return true;
}
int main()
{
    int n;
    job row[5005],col[5005];
    int rpos[5005],cpos[5005];
    while(scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++)
        {
            row[i].index=col[i].index =i;
            scanf("%d%d%d%d",&row[i].s,&col[i].s,&row[i].e,&col[i].e);
        }
        sort(row+1,row+n+1);
        sort(col+1,col+n+1);
        if(solve(row,n,rpos)&&solve(col,n,cpos))
        {
            for(int i=1;i<=n;i++)
            {
                printf("%d %d\n",rpos[i],cpos[i]);
            }
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}
