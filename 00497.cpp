#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

vector<int> in,last;

int getact(int l,int r,int key)
{
    while(r>l)
    {
        int mid = (r+l)/2;
        if(in[last[mid]]>=key)
            r = mid;
        else
            l = mid+1;
    }
    return l;
}
int main()
{
    char input[50];
    int t;
    cin>>t;
    cin.getline(input,50);
    cin.getline(input,50);
    while(t--)
    {
        in.clear();
        last.clear();
        while(1)
        {
            cin.getline(input,50);
            if(cin.eof())
                break;
            if(input[0]=='\0')
                break;
            int num= atoi(input);
            in.push_back(num);
        }
        vector<int> pre(in.size(),-1);
        for(int i=0;i<in.size();i++)
        {
            if(last.empty())
            {
                last.push_back(i);
                pre[i] = -1;
            }
            else if(in[i]>in[last[last.size()-1]])
            {
                pre[i] = last[last.size()-1];
                last.push_back(i);
            }
            else if(in[i]<in[last[0]])
            {
                pre[i] = -1;
                last[0] = i;
            }
            else
            {
                int v=getact(0,last.size()-1,in[i]);
                last[v] = i;
                pre[i] = last[v-1];
            }
        }
        printf("Max hits: %d\n",last.size());
        vector<int> ans;
        for(int i=last[last.size()-1];i>=0;i = pre[i])
        {
            ans.push_back(in[i]);
        }
        for(int i=ans.size()-1;i>=0;i--)
            cout<<ans[i]<<endl;
        if(t)
            printf("\n");
    }
    return 0;
}
