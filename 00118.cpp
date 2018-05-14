#include <bits/stdc++.h>
#define s1 first
#define s2 second
using namespace std;

int main()
{
    //freopen("in.txt", "rt", stdin);
//freopen("out.txt", "w+t", stdout);
    map<char,pair<int,int>> dir;
    dir['E'] = pair<int,int>(0,1);
    dir['W'] = pair<int,int>(0,-1);
    dir['N'] = pair<int,int>(1,0);
    dir['S'] = pair<int,int>(-1,0);
    map< pair<int,int>,char> ndir;
    ndir[pair<int,int>(0,1)] = 'E';
    ndir[pair<int,int>(0,-1)] = 'W';
    ndir[pair<int,int>(1,0)] = 'N';
    ndir[pair<int,int>(-1,0)] = 'S';
    int w,h,x,y,xx,yy;
    char fd;
    string com;
    cin>>w>>h;
    bool scent[h+1][w+1];
    memset(scent,0,sizeof(bool)*(h+1)*(1+w));
    while(cin>>x>>y>>fd)
    {
        //cout<<fd<<endl;
        cin>>com;
        pair<int,int> cur = dir[fd];
        int i;
        for(i=0; i<com.size(); i++)
        {
            if(com[i]=='R')
            {
                swap(cur.s1,cur.s2);
                cur.s1 *= (-1);
            }
            else if(com[i]=='L')
            {
                swap(cur.s1,cur.s2);
                cur.s2 *= (-1);
            }
            else if(com[i]=='F')
            {
                yy = y + cur.s1;
                xx = x + cur.s2;
                if(xx<0 || xx>w || yy<0 || yy>h)
                {
                    if(scent[y][x])
                    {
                        continue;
                    }
                    printf("%d %d %c LOST\n",x,y,ndir[cur]);
                    scent[y][x] = true;
                    break;
                }
                x = xx;
                y = yy;
            }
           // printf("%d %d %c\n",x,y,ndir[cur]);
        }
        if(i==com.size())
        {
            printf("%d %d %c\n",x,y,ndir[cur]);
        }
    }
    return 0;
}
