//in the name of ALLAH
#include<bits/stdc++.h>
#define mx 10000001
using namespace std;
typedef uint64_t ll;
 ll dp[mx];
 ll mod=1000000007;
void solve()
{

    dp[0]=1;
    for(int i=1;i<mx;i++)
    {
        dp[i]=((dp[i-1]%mod)*(i%mod))%mod;
    }
}
int main()
{
    solve();
    ll t;
    cin>>t;
    for(int te=1;te<=t;te++)
    {
     ll n;
     cin>>n;
     ll x=dp[n]%mod;
     cout<<"Case "<<te<<": "<<x<<endl;

    }
}
