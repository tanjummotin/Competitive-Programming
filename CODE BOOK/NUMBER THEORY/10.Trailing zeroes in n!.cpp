///in the name of ALLAH
///Trailing zeros in n!
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll findzero(ll n)///count how many 5 in n.The number of 5 present=the number of trailing zeros because 2*5 pair make trailing zeros.In a number always number of 2 is
{                   ///always greater than 5 .So,we counted number of 5.
    ll x=n;
    ll freq=0;
    while(x)
    {
        freq+=x/5;
        x=x/5;

    }
    return freq;
}
int main()
{
    int t;cin>>t;
    while(t--){
    ll n;
    cin>>n;
    cout<<findzero(n)<<endl;;
    }

}

