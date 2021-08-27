///BISMILLAHIR RAHMANIR RAHIM
///Problem name:Range minimum query using sqrt decomposition
///Tutorial:https://www.youtube.com/watch?v=o7278rPg_9I&list=PL2q4fbVm1Ik7Ds5cuaoOmExjOQG31kM-p&index=1&t=1103s
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll block=700;
const ll mx=1e15;
ll f[block+5],a[100005];
ll getmin(ll l,ll r)
{
    ll LB=l/block;
    ll RB=r/block;
    ll mn=mx;
    if(LB==RB)
    {
       for(int i=l;i<=r;i++)
            mn=min(a[i],mn);
    }
    else
    {
        for(int i=l;i<block*(LB+1);i++)
            mn=min(mn,a[i]);

        for(int i=LB+1;i<RB;i++)
            mn=min(mn,f[i]);

        for(int i=block*RB;i<=r;i++)
            mn=min(mn,a[i]);
    }
    return mn;
}
int main()
{
    ll n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<=block; i++)
        f[i]=mx;
    for(int i=0; i<n; i++)
    {
        if(f[i/block]==mx)
            f[i/block]=a[i];
        else
            f[i/block]=min(f[i/block],a[i]);
    }
    ll query,l,r;
    cin>>query;
    for(int i=0;i<query;i++)
    {
        cin>>l>>r;
        cout<<getmin(l,r)<<endl;
    }
}
