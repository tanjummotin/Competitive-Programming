#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>digit;
ll dp[10][2][99];

 bool is_prime(ll x)
 {
     bool f=1;
     for(int i=2;i<=sqrt(x);i++)
     {
         if(x%i==0)
         {
             f=0;break;
         }
     }
     return f;
 }
ll sol(ll pos,bool is_small,ll sum)
{
    if(pos>=digit.size())
    {
        if(is_prime(sum) && sum!=1)
            return 1;
        else
            return 0;
    }
    if(dp[pos][is_small][sum]!=-1)
        return dp[pos][is_small][sum];
    ll limit=digit[pos];
    if(is_small)
        limit=9;
    ll val=0;
    for(ll i=0; i<=limit; i++)
    {
        val+=sol(pos+1,(i<digit[pos])|is_small,sum+i);
    }
    return dp[pos][is_small][sum]=val;
}
void convert(ll x)
{
    while(x)
    {
        digit.push_back(x%10);
        x/=10;
    }
    reverse(digit.begin(),digit.end());
}
int main()
{
    ll t;
    cin>>t;
    while(t--){
    ll a,b,r,l;
    cin>>a>>b;
    convert(b);
    memset(dp,-1,sizeof dp);
    r=sol(0,0,0);
    digit.clear();

    convert(a-1);
    memset(dp,-1, sizeof dp);
    l=sol(0,0,0);
    digit.clear();
    cout<<r-l<<endl;
    }

}


