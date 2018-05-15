#include <bits/stdc++.h>

using namespace std;

bool bpm[3005][2005];
int nm,nn,cn;
bool connect[3005][3005];
void floyd()
{
    for(int i=0;i<nn;i++)
    {
        for(int j=0;j<nn;j++)
        {
            for(int k=0;k<nn;k++)
            {
                if(connect[i][k]&&connect[k][j])
                    connect[i][j] = true;
            }
        }
    }
}
bool isBpm(int u,bool seen[],int matchR[])
{
    for(int v=0;v<nm;v++)
    {
        if(bpm[u][v] && !seen[v])
        {
            seen[v] = true;

            if(matchR[v]<0 || isBpm(matchR[v],seen,matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
int maxP()
{
    int match[nm];
    bool seen[nm];
    fill_n(match,nm,-1);
    int ans(0);
    for(int u=0;u<cn;u++)
    {
        memset(seen,0,sizeof(seen));
        if(isBpm(u,seen,match))
            ans++;
    }
    return ans;
}
int main()
{
    //freopen("in.txt", "rt", stdin);
//reopen("out.txt", "w+t", stdout);
    int t,n,m,k;
    scanf("%d\n",&t);
    while(t--)
    {
        //cout<<t<<endl;
        nm = nn =0;
        memset(bpm,0,sizeof(bpm));
        memset(connect,0,sizeof(connect));
        map<string,int> rec;
        map<string,int> dev;
        scanf("%d",&n);
        string input1,input2;
        int cnt[3005];
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
        {
            cin>>input1;
            if(rec.find(input1)==rec.end())
                rec[input1] = nn++;
            cnt[rec[input1]]++;
        }
        cn = nn;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            cin>>input2>>input1;
            if(rec.find(input1)==rec.end())
            {
                rec[input1] = nn++;
            }
            dev[input2] = nm++;
            bpm[rec[input1]][dev[input2]] = true;
        }
        scanf("%d",&k);
        for(int i=0;i<k;i++)
        {
            cin>>input1>>input2;
            if(rec.find(input1)==rec.end())
                rec[input1] = nn++;
            if(rec.find(input2)==rec.end())
                rec[input2] = nn++;
            int a = rec[input1];
            int b = rec[input2];
            connect[a][b] = true;
        }
        floyd();
        for(int i=0;i<nn;i++)
        {
            for(int j=0;j<nn;j++)
            {
                if(connect[i][j])
                {
                    for(int k=0;k<nm;k++)
                    {

                        bpm[j][k] = bpm[i][k]|bpm[j][k];
                    }
                }
            }
        }
        int l = cn;
        for(int i=0;i<l;i++)
        {
            int dn = cn;
            cn = cn+cnt[i]-1;
            for(int j=dn;j<cn;j++)
            {
                for(int k=0;k<nm;k++)
                    bpm[j][k] = bpm[i][k];
            }

        }
        cout<<nm - maxP()<<endl;
        if(t)
            cout<<endl;
    }
    return 0;
}
