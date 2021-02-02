#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k;
vector<ll>digit;
ll dp[10][2][100][100];
ll p10[11];
void power()
{
    p10[0]=1;
    for(int i=1;i<=10;i++)
    {
        p10[i]=p10[i-1]*10;
    }
}
ll sol(ll pos,bool is_small,ll sum,ll till_mod)
{
    if(pos>=digit.size())
    {
        if(sum%k==0 && till_mod==0)
            return 1;
        else
            return 0;
    }
    if(dp[pos][is_small][sum][till_mod]!=-1)
        return dp[pos][is_small][sum][till_mod];
    ll limit=digit[pos];
    if(is_small)
        limit=9;
    ll val=0;
    for(ll i=0; i<=limit; i++)
    {
        ll sz=digit.size()-pos-1;
        val+=sol(pos+1,(i<digit[pos])|is_small,sum+i,((till_mod+(i*p10[sz])%k)%k));
    }
    return dp[pos][is_small][sum][till_mod]=val;
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
    power();
    int t;
    cin>>t;
    for(int te=1;te<=t;te++)
    {
        ll a,b,r,l,ans;
        cin>>a>>b>>k;
        if(k>82)ans=0;
        else{
        convert(b);
        memset(dp,-1,sizeof dp);
        r=sol(0,0,0,0);
        digit.clear();

        convert(a-1);
        memset(dp,-1, sizeof dp);
        l=sol(0,0,0,0);
        digit.clear();
        ans=r-l;
        }
        //cout<<r<<" "<<l<<endl;
        cout<<"Case "<<te<<": "<<ans<<endl;
    }

}


