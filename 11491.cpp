#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    int n,d,num[100005];
    while(scanf("%d%d",&n,&d))
    {
        if(n==0&&d==0)
            break;
        cin>>input;
        int index(0),cnt(0);
        for(int i=0;i<n;i++)
            num[i] = input[i]-'0';
        for(int i=1;i<n;i++)
        {
            while(index>=0 && cnt<d && num[i]>num[index])
            {
                index--;
                cnt++;
            }
            num[++index] = num[i];
        }
        for(int i=0;i<n-d;i++)
            printf("%d",num[i]);
        printf("\n");
    }
    return 0;
}
