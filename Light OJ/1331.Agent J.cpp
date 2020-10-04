///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    for(int te=1;te<=t;te++)
    {
        double r1,r2,r3;
        cin>>r1>>r2>>r3;
        double a,b,c,A,B,C,s1,s2,x;
        a=r2+r3;b=r1+r3;c=r1+r2;
        A=acos((b*b+c*c-a*a)/(2.00*b*c));
        B=acos((a*a+c*c-b*b)/(2.00*a*c));
        C=acos((a*a+b*b-c*c)/(2.00*a*b));
        x=(a+b+c)/2.00;
        s1=sqrt(x*(x-a)*(x-b)*(x-c));
        s2=((r1*r1*A)/2.00)+((r2*r2*B)/2.00)+((r3*r3*C)/2.00);
        cout<<"Case "<<te<<": "<<fixed<<setprecision(10)<<s1-s2<<endl;


    }
}
