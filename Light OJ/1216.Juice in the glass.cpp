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
        int r1,r2,h,p;
        cin>>r1>>r2>>h>>p;
        double h1=(r2*h)/(double)(r1-r2);
        double r3=((p+h1)*r2)/(double)h1;
        double v=(1/3.00)*pi*p*(r3*r3+r3*r2+r2*r2);
        cout<<"Case "<<i<<": "<<fixed<<setprecision(9)<<v<<endl;
    }
}
