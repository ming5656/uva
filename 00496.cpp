#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    char input[4096],*p;
    int a[500],b[500];
    bool visit[500];
    while(cin.getline(input,4096))
    {
        fill_n(visit,500,false);
        int anum(1),bnum(1),equ(0);
        p=strtok(input," ");
        a[0]=atoi(p);
        while(1)
        {
            p=strtok(NULL," ");
            if(p==NULL)
                break;
            a[anum++]=atoi(p);
        }
        cin.getline(input,4096);
        p=strtok(input," ");
        b[0]=atoi(p);
        while(1)
        {
            p=strtok(NULL," ");
            if(p==NULL)
                break;
            b[bnum++]=atoi(p);
        }
        sort(a,a+anum);
        sort(b,b+bnum);
        for(int i=0;i<bnum;i++)
        {
            for(int j=0;j<anum;j++)
            {
                if(a[j]>b[i])
                    break;
                if(a[j]==b[i]&&!visit[i])
                {
                    equ++;
                    visit[i]=true;
                    break;
                }
            }
        }
        if(anum==bnum&&anum==equ)
        {
            cout<<"A equals B"<<endl;
        }
        else if(equ==0)
        {
            cout<<"A and B are disjoint"<<endl;
        }
        else if(bnum==equ&&anum>equ)
        {
            cout<<"B is a proper subset of A"<<endl;
        }
        else if(anum==equ&&bnum>equ)
        {
            cout<<"A is a proper subset of B"<<endl;
        }
        else
        {
            cout<<"I'm confused!"<<endl;
        }
    }
    return 0;
}
