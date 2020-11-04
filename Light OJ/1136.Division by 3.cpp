///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        ll s1=(b/3)*2;
        if(b%3!=0 && (b+2)%3!=0)s1++;
         ll s2=(a/3)*2;
        if(a%3!=0 && (a+2)%3!=0)s2++;
        cout<<"Case "<<i<<": "<<s1-s2<<endl;
    }
}
