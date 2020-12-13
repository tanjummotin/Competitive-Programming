///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef uint64_t ll;
ll dp[201][12];
ll nCr(ll n,ll r)
{
    if(n==r) return 1;
    if(r==1) return n;
    if(r==0) return 1;
    if(dp[n][r])return dp[n][r];
    return dp[n][r]=nCr(n-1,r)+nCr(n-1,r-1);
}
int main()
{
    ll n,r;
    cin>>n>>r;
    cout<<nCr(n,r)<<endl;;

}

