///BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<pair<ll, ll>, null_type,less<pair<ll, ll> >, rb_tree_tag,tree_order_statistics_node_update>Multiset;

///order_of_key-->the number of items in a set that are strictly smaller than our item
int main()
{
    fastio;
    ll t;
    cin>>t;
    while(t--)
    {
       ll n;
       cin>>n;
       ll a[n],ans=0;
       Multiset ms;
       for(int i=0;i<n;i++)
       {
           cin>>a[i];
       }
       cout<<endl;
       for(int i=0;i<n;i++)
       {
           ll p=ms.order_of_key({a[i],n+1});
           //cout<<ms.size()-p<<" "<<ms.size()<<" "<<p<<endl;
           ans+=(ms.size()-p);
           ms.insert({a[i],i});
       }
       cout<<ans<<endl;
    }
}

/*
2

3
3
1
2

5
2
3
8
6
1
Ans= 2 5
*/
