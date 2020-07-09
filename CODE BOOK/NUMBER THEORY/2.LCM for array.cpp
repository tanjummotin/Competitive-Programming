#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll findlcm(ll temp[],int x)
{
    ll ans=temp[0];
    for(int i=1; i<x; i++)
    {
        ans=(temp[i]*ans)/(gcd(temp[i],ans));
    }
    return ans;
}
int main()
{
   ll n;
   cin>>n;
   ll arr[n];
   for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<findlcm(arr,n)<<endl;;
}

