#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
   if(a==0)
        return b;
    else if(b==0)
        return a;
        else if(a%b==0)
            return b;
        return gcd(b,a%b);
        }
int main()
{
    long long a,b,t;
    cin>>t;
    while(t--){
            cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    }
}
