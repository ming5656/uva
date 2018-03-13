#include <bits/stdc++.h>

using namespace std;
struct dir
{
    int x,y;
};
dir mv[] = {{1,0},{1,1},{1,-1},{-1,0},{-1,1},{-1,-1},{0,1},{0,-1}};
int main()
{
    //freopen("in.txt", "rt", stdin);
//freopen("out.txt", "w+t", stdout);
    int mines[100][100],n,m,kase(0);
    char field[101][101];
    while(scanf("%d%d",&n,&m)&&n&&m)
    {
        if(kase)
            cout<<endl;
        char l[5];
        fgets(l,5,stdin);
        for(int i=0; i<n; i++)
        {
            fgets(field[i],m+1,stdin);
            fgets(l,5,stdin);
        }
        memset(mines,0,sizeof(mines));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(field[i][j] == '*')
                {
                    for(int k=0; k<8; k++)
                    {
                        if(i+mv[k].x <0 || i +mv[k].x >=n || j+ mv[k].y<0 || j+ mv[k].y  >= m)
                        {
                            continue;
                        }
                        mines[i+mv[k].x][j+mv[k].y]++;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(field[i][j]!='*')
                    field[i][j] = '0' + mines[i][j] ;
            }
        }
        cout<<"Field #"<<++kase<<":"<<endl;
        for(int i=0;i<n;i++)
            cout<<field[i]<<endl;
    }
    return 0;
}
