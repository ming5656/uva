#include <bits/stdc++.h>
#define MIN_NUM -99999999
using namespace std;

int main()
{
    int n;
    pair<int,int> boxes[1005];
    int num[6005];
    while(scanf("%d",&n)!=EOF&&n)
    {
        int a,b;
        fill_n(num,6005,MIN_NUM);
        num[0] =0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            boxes[i].first = a;
            boxes[i].second = b;
            //first =  weight ,second = load
        }
        int ans(0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=6004;j>=boxes[i].first;j--)
            {
                if(num[j]<num[j-boxes[i].first]+1&&boxes[i].second>=j-boxes[i].first)
                {
                    num[j]=num[j-boxes[i].first]+1;
                }
                ans=max(ans,num[j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
