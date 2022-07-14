///BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mx 1000002
using namespace std;
typedef long long ll;


ll mp[1000005];

int main()
{

    ll cnt=0;
    for(ll i=2; i<=1000000; i++)
    {
        for(ll j=2*i; j<=1000000; j+=i)
        {
            // cnt++;
            mp[j]++;
        }

    }

    for(int i=1; i<=100; i++)
    {
        cout<<"i--- "<<i<<" "<<mp[i]+1<<endl;
    }
}



