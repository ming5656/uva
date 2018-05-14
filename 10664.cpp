#include <bits/stdc++.h>

using namespace std;

int w[25];
int main()
{
    //freopen("in.txt", "rt", stdin);
//freopen("out.txt", "w+t", stdout);
    int t;
    scanf("%d\n",&t);
    char buffer[1024];
    while(t--)
    {
        fgets(buffer,1024,stdin);
        int len(0),total(0);
        char *p = strtok(buffer," ");
        w[len++] = atoi(p);
        total = w[0];
        while(1)
        {
            p = strtok(NULL," ");
            if(p==NULL)
                break;
            w[len] = atoi(p);
            total+=w[len++];
        }
        if(total&1)
        {
            printf("NO\n");
            continue;
        }
        bool f[total+1];
        memset(f,0,sizeof(bool)*(total+1));
        f[0] = 1;
        total/=2;
        for(int i=0;i<len;i++)
        {
            for(int j=total;j>=w[i];j--)
            {
                if(f[j-w[i]])
                    f[j] = 1;
            }
            if(f[total])
                break;
        }

        if(f[total])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
