#include <cstdio>
#include <cstring>
#define MAXN 2000005
using namespace std;

short int arr[MAXN];
int link[MAXN];

int radixSort(int n)
{
    int first = 1,last = 0,bin;
    for(int i=1;i<=n;i++)
        link[i] = i+1;
    link[n] = 0;
    int f[10],r[10];
    for(int i=1;i<=100;i*=10)
    {
        memset(f,0,sizeof(f));
        for(int cur = first;cur;cur = link[cur])
        {
            bin = (arr[cur]/i) %10;
            if(f[bin] == 0)
            {
                f[bin] = cur;
                r[bin] = cur;
            }
            else
            {
                link[r[bin]] = cur;
                r[bin] = cur;
            }
        }
        for(bin = 0; bin<10 &&!f[bin];bin++);
        first = f[bin];
        last = r[bin];
        bin++;
        for(bin;bin<10;bin++)
        {
            if(f[bin])
            {
                link[last] = f[bin];
                last = r[bin];
            }
        }
        link[last] = 0;
    }
    return first;
}

void listSort(int first,int n)
{
    int index;
    if(n!=0)
    {
        printf("%hd",arr[first]);
        index = link[first];
    }
    for(int j=2;j<=n;j++)
    {
        printf(" %hd",arr[index]);
        index = link[index];
    }
    puts("");
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%hd",&arr[i]);
        }
        int first = radixSort(n);
        listSort(first,n);
    }
    return 0;
}
