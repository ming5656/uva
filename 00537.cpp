#include <iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>

using namespace std;

double cutText(char *str,char unit)
{
    double ans;
    char intt[100],*p;
    if(unit =='A')
        p = strstr(str,"I=");
    else if(unit=='V')
        p = strstr(str,"U=");
    else if(unit=='W')
        p = strstr(str,"P=");
    p+=2;
    int i;
    for(i=0; p[i]!='m'&&p[i]!='k'&&p[i]!='M'&&p[i]!=unit; i++)
    {
        intt[i] = p[i];
    }
    intt[i]='\0';
    ans = atof(intt);
    if(p[i]=='k')
    {
        ans*=1000;
    }
    else if(p[i]=='m')
    {
        ans/=1000;
    }
    else if(p[i]=='M')
    {
        ans*=1000000;
    }
    return ans;
}
int main()
{
    //freopen("in.txt", "rt", stdin);
//freopen("out.txt", "w+t", stdout);

    int t;
    scanf("%d\n",&t);
    char text[4096];
    for(int kase = 1; kase<=t; kase++)
    {
        fgets(text,4096,stdin);
        char *p;
        printf("Problem #%d\n",kase);
        if((p=strstr(text,"P="))==NULL)
        {
            double a,v;
            a = cutText(text,'A');
            v = cutText(text,'V');
            printf("P=%.2fW\n",a*v);
        }
        else if((p=strstr(text,"U="))==NULL)
        {
            double a,w;
            a = cutText(text,'A');
            w = cutText(text,'W');
            printf("U=%.2fV\n",w/a);
        }
        else if((p=strstr(text,"I="))==NULL)
        {
            double w,v;
            w = cutText(text,'W');
            v = cutText(text,'V');
            printf("I=%.2fA\n",w/v);
        }
            cout<<endl;
    }
    return 0;
}
