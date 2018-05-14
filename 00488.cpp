#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt", "rt", stdin);
//freopen("out.txt", "w+t", stdout);

    int t,a,f;
    cin>>t;
    while(t--)
    {
        cin>>a>>f;
        for(int i=0;i<f;i++)
        {
            for(int j=1;j<=a;j++)
            {
                for(int k=0;k<j;k++)
                {
                    printf("%d",j);
                }
                printf("\n");
            }
            for(int j=a-1;j>=1;j--)
            {
                for(int k=0;k<j;k++)
                {
                    printf("%d",j);
                }
                printf("\n");
            }
            if(t!=0 || i!=f-1)
                printf("\n");
        }
    }
    return 0;
}
