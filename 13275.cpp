#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t,d,m,y,qy;
    scanf("%d",&t);
    for(int kase =1;kase<=t;kase++)
    {
        scanf("%d%d%d%d",&d,&m,&y,&qy);
        if(d!=29||m!=2)
        {
            printf("Case %d: %d\n",kase,qy-y);
        }
        else
        {
            int ny(0);
            for(int i = y+4 ; i<=qy ;i+=4)
            {

                if(i %400==0)
                    ny++;
                else if(i %100!=0 && i %4==0)
                    ny++;
            }
            printf("Case %d: %d\n",kase,ny);
        }
    }
    return 0;
}
