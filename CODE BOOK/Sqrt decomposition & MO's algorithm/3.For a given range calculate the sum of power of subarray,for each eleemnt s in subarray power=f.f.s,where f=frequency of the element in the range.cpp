///3.For a given range calculate the sum of power of subarray,for each eleemnt s in subarray power=f*f*s,where f=frequency of the element in the range.cpp
///CF-86D,powerful array
///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> z_array(vector<ll>s)
{
    ll nf=s.size();
    vector<ll>z(nf,0);

    ll l=0,r=0;
    for(ll i=1; i<nf; i++)
    {
        if(i<=r)
        {
            z[i]=min(r-i+1LL,z[i-l]);
        }
        while(i+z[i]<nf && s[z[i]]==s[i+z[i]])
        {
            z[i]++;
        }
        if(i+z[i]-1>r)
        {
            l=i;
            r=i+z[i]-1;
        }
    }
    return z;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    ll a1[n+5],a2[m+5];
    for(ll i=0; i<n; i++)
        cin>>a1[i];
    for(ll i=0; i<m; i++)
        cin>>a2[i];
    if(n<m)
    {
        cout<<0<<endl;
    }
    else if(m==1)
    {

        cout<<n<<endl;
    }
    else
    {
        for(ll i=0; i<n-1; i++)
        {
            a1[i]=a1[i]-a1[i+1];
        }
        for(ll i=0; i<m-1; i++)
        {
            a2[i]=a2[i]-a2[i+1];
        }
        n--;
        m--;
        vector<ll>a3;
        for(ll i=0; i<m; i++)
            a3.push_back(a2[i]);
        a3.push_back(INT_MAX);


        for(ll i=0; i<n; i++)
            a3.push_back(a1[i]);


        vector<ll>z=z_array(a3);

        ll ans=0;
        for(ll i=0; i<z.size(); i++)
        {
            if(z[i]==m)
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }

}

