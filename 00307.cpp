#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<cstdio>
using namespace std;

vector<int> divisor;
int *visit,n;
void allDivisor(int n,int low)
{
    divisor.clear();
    for(int i=low; i<=n; i++)
    {
        if(!(n%i))
        {
            divisor.push_back(i);
        }
    }
}
bool dfs(int s,int add,int t,int stick[],int cnt)
{
    if(cnt == 1)
        return true;
    if(add == t)
    {
        if(dfs(0,0,t,stick,cnt-1))
            return true;
        return false;
    }
    else if(add < t)
    {
        for(int i=s;i < n;i++)
        {
            if(add + stick[i] > t)
                i++;
            if(visit[i])
                continue;
            visit[i] =true;
            if(dfs(i+1,add+stick[i],t,stick,cnt))
                return true;
            visit[i] =false;
            if(add == 0)
                return false;
            while(i+1 <n && stick[i] == stick[i+1])
                i++;
        }
        return false;
    }
    else
    {
        return false;
    }

    return false;
}
int main()
{
    while(scanf("%d",&n) && n)
    {
        int sum(0),stick[n];
        visit = new int[n];
        for(int i=0; i<n; i++)
        {
            scanf("%d",&stick[i]);
            sum += stick[i];
        }
        sort(stick, stick + n,greater<int>());
        allDivisor(sum,stick[0]);
        //for(int i=0;i<divisor.size();i++)
            //cout<<divisor[i]<<endl;
        //for(int i=0;i<n;i++)
            //cout<<stick[i]<<endl;
        for(int i=0; i<divisor.size(); i++)
        {
            //cout<< divisor[i] <<endl;
            fill_n(visit,n,false);
            if(dfs(0,0,divisor[i],stick,sum/divisor[i]))
            {
                cout<<divisor[i]<<endl;
                break;
            }
        }
        delete []visit;
    }
    return 0;
}
