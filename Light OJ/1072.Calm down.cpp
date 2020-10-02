///in the name of ALLAH
#include<bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        double R,r;
        int n;
        cin>>R>>n;
        double theta=((90.0-(180.0/(double)n))*pi)/180.00;
         //cout<<theta<<" "<<cos(theta)<<endl;
         r=(R*cos(theta))/(double)(1.00+cos(theta));
        cout<<"Case "<<i<<": "<<fixed<<setprecision(10)<<r<<endl;
    }
}
