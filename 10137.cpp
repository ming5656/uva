#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    double cost[1005];
    while(cin>>n && n)
    {
        double average = 0.0,height=0.0,low = 0.0;
        for(int i=0;i<n;i++)
        {
            cin>>cost[i];
            average+=cost[i];
        }
        average = ((double)(int)(average*100/n+0.5))/100;
        for(int i=0;i<n;i++)
        {
            if(cost[i]>average)
            {
                height += double(cost[i] - average);
            }
            else if(cost[i]<average)
            {
                low += double(average - cost[i]);
            }
        }
        double ans = (height < low)?height:low ;
        cout << "$"<<fixed << setprecision (2)<<ans << endl;
    }
    return 0;
}
