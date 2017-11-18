#include<bits/stdc++.h>

using namespace std;
//dp[i][j]=sum[i][j]-min(dp[i][j-k],dp[i+k][j]);
int main()
{

    int num[105],n,dp[105][105],sum[105][105];
    while(scanf("%d",&n)!=EOF&&n)
    {
        int len(0);
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&num[i]);
        }
        for(int i=0;i<n;i++)
        {
            sum[i][i] = num[i];
            for(int j=i+1;j<n;j++)
            {
                sum[i][j] = sum[i][j-1]+num[j];
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            dp[i][i]=num[i];
        for(int i = n-2 ;i>=0 ;i--)
        {
            for(int j = i+1; j<n;j++)
            {
                int minV =INT_MAX;
                for(int k=n-1;k>i;k--)
                {
                    minV = min(minV,dp[k][j]);
                }
                for(int k=i;k<j;k++)
                {
                    minV = min(minV,dp[i][k]);
                }
                dp[i][j] = max(sum[i][j],sum[i][j] - minV);
                //printf("%d\n",dp[i][j]);
            }
        }
        printf("%d\n",dp[0][n-1]*2-sum[0][n-1]);
    }
    return 0;
}
