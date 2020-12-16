///in the name of ALLAH
///Calculate nCr%mod;n,r<=2*10^5
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX=2e5+5;
const int mod=1e9+7;

ll big_mod(ll a,ll b,ll mod)
{
    if(b==0)
        return 1%mod;
    ll x=big_mod(a,b/2,mod);
    x=(x*x)%mod;
    if(b%2==1)
        x=(x*a)%mod;
    return x;
}

ll inverse_mod(ll n, ll mod)///modulo inverse
{
    return big_mod(n,mod-2,mod);
}

///Calculates nCr%mod
///pre_calc_fact() function must be called

ll fact[MX];

void pre_calc_fact(ll n, ll mod)///Pre-calculating factorial
{
    fact[0]=1;
    for(ll i=1; i<=n; ++i)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
}

ll nCr(ll n, ll r, ll mod)
{
    if(r>n)
        return 0;
    return (fact[n]*inverse_mod((fact[r]*fact[n-r])%mod, mod))%mod;///because nCr=n!/(r!*(n-r)!)
}
int main()
{
    pre_calc_fact(MX-1, mod);
    ll t;
    cin>>t;
    while(t--)
    {
       ll n,r;
       cin>>n>>r;
       cout<<nCr(n,r,mod)<<endl;
    }
}




