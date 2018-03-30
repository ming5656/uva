#include <bits/stdc++.h>

struct pos
{
    int x,y;
};
using namespace std;

bool adj[105][105],seen[105];
int matchR[105];
pos bob[105], dog[105];
int n,m,l,dogRoute[105],result;
int dis(pos a, pos b)
{
    return pow(a.x - b.x ,2) + pow(a.y-b.y, 2);
}
void creatAdj()
{
    for(int i=1;i < n ;i++)
    {
        for(int j=1; j <=m ;j++)
        {
            double p = dis(bob[i-1],bob[i]);
            double q1 = dis(bob[i-1],dog[j]);
            double q2 = dis(bob[i],dog[j]);
            if(sqrt(p)*2 >= sqrt(q1)+sqrt(q2))
            {
                adj[i-1][j] = true;
            }
        }
    }
}
bool bpm(int s)
{
    for(int i=1 ; i<= m ;i++)
    {
        if(adj[s][i] && !seen[i])
        {
            seen[i] = true;
            if(dogRoute[i]== -1 || bpm(dogRoute[i]))
            {
                dogRoute[i] = s;
                matchR[s] = i;
                return true;
            }
        }
    }
    return false;
}
void maxBpm()
{
    result = 0;
    for(int i=0; i<n-1;i++)
    {
        memset(seen,0,sizeof(bool)*105);
        if(bpm(i))
        {
            result++;
        }
    }
}
int main()
{
    cin>>l;
    while(l--)
    {
        memset(adj,0,sizeof(bool)*105*105);
        fill_n(dogRoute,105,-1);
        fill_n(matchR,105,-1);
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>> bob[i].x >> bob[i].y;
        }
        for(int i=1; i <= m; i++ )
        {
            cin>> dog[i].x >> dog[i].y;
        }
        creatAdj();
        maxBpm();
        cout<<result + n<<endl;
        for(int i=0;i<n;i++)
        {
            if(i)
                cout<<" ";
            cout<<bob[i].x<<" "<<bob[i].y;
            if(matchR[i] !=-1)
            {
                cout<<" "<<dog[matchR[i]].x<<" "<<dog[matchR[i]].y;
            }
        }
        cout<<endl;
        if(l)
            cout<<endl;
    }
    return 0;
}
