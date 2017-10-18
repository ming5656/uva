#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int tree[40960000];
bool visit[40960000];
void inorder(int root,int &con)
{
    if(visit[root])
    {
        con++;
        inorder(root*2+1,con);
        inorder(root*2+2,con);
    }
}
bool isComplete(int num)
{
    int con(0);
    inorder(0,con);
    if(num==con)
        return true;
    else
        return false;
}

int main()
{
    //freopen("in.txt","rt",stdin);
    //freopen("out.txt","w+t",stdout);
    char input[1024],*p;
    int num(0);
    while(cin>>input)
    {
        if(strcmp(input,"()")==0)
        {
            if(isComplete(num))
            {
                for(int i=0,j=0; j<num; i++)
                {
                    if(visit[i])
                    {
                        if(i)
                            cout<<" ";
                        cout<<tree[i];
                        j++;
                    }
                }
                cout<<endl;
            }
            else
            {
                cout<<"not complete"<<endl;
            }
            fill_n(visit,4096,false);
            num=0;
        }
        else
        {
            char buffer[4096];
            strcpy(buffer,input+1);
            p=strtok(buffer,",");
            int v=atoi(p);
            p=strstr(input,",");
            p++;
            int index(0);
            for(int i=0; p[i]!=')'; i++)
            {
                index*=2;
                if(p[i]=='L')
                    index+=1;
                else if(p[i]=='R')
                    index+=2;
            }
            tree[index]=v;
            visit[index]=true;
            num++;
        }
    }
    return 0;
}
