#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,ans[25],student[25],k,rak[25],lev[25];
    vector<int> last;
    char input[100];
    bool e(false);
    fgets(input,100,stdin);
    n=atoi(input);
    while(1)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&k);
            rak[k-1]=i;
        }
        for(int i=0;i<n;i++)
        {
            ans[rak[i]]=i;
        }
        if(fgets(input,100,stdin)==NULL)
        {
            break;
        }
        while(1)
        {
            if(fgets(input,100,stdin)==NULL)
            {
                e = true;
                break;
            }
            else
            {
                if(strstr(input," ")==NULL)
                {
                    n= atoi(input);
                    break;
                }
                else
                {
                    char *ptr = input;
                    for(int i=0;i<n;i++)
                    {
                        sscanf(ptr,"%d",&k);
                        lev[k-1] = i;
                        ptr+=2;
                        if(ptr[0]==' ')
                            ptr++;
                    }
                }
            }
            for(int i=0;i<n;i++)
            {
                student[i] = ans[lev[i]];
            }
            last.clear();
            last.push_back(-1);
            vector<int>::iterator it;
            for(int i=0;i<n;i++)
            {
                it = lower_bound(last.begin(),last.end(),student[i]);
                if(it==last.end())
                {
                    last.push_back(student[i]);
                }
                else
                {
                    *it=student[i];
                }
            }
            printf("%d\n",last.size()-1);
        }
        if(e)
            break;
    }
    return 0;
}
