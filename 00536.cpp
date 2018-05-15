#include <iostream>
#include <cstring>

using namespace std;

void solve(char in[],char pre[],char post[],int &pos,int ibegin,int iend,int root)
{
    if(ibegin==iend)
    {
        post[pos--]=in[ibegin];
        return;
    }
    post[pos--]=pre[root];
    for(int i=ibegin;i<=iend;i++)
    {
        if(in[i]==pre[root])
        {
            if(iend>=i+1)
                solve(in,pre,post,pos,i+1,iend,root+i-ibegin+1);
            if(i-1>=ibegin)
                solve(in,pre,post,pos,ibegin,i-1,root+1);
        }
    }
}
int main()
{
    char inorder[26],preorder[26],postorder[26];
    int pos,len;
    while(cin>>preorder)
    {
        cin>>inorder;
        len=pos=strlen(inorder)-1;
        solve(inorder,preorder,postorder,pos,0,len,0);
        postorder[len+1]='\0';
        cout<<postorder<<endl;
    }
    return 0;
}
