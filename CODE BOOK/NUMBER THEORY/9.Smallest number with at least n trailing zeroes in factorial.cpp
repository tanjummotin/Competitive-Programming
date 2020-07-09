///in the name of ALLAH
///Smallest number with at least n trailing zeros in factorial
///Tutorial:https://www.geeksforgeeks.org/smallest-number-least-n-trailing-zeroes-factorial/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll trailingZeroInFactorial(ll num)
{
    ll x=num;
    ll freq=0;
    while(x)
    {
        freq+=x/5;
        x=x/5;

    }
    return freq;
}
ll smallestNum(ll q)
{
    if(q==1)
        return 5;
        ll low=0;
        ll high=5*q;
        while(low<high)
        {
            ll mid=(low+high) >> 1;///>> 1 means divide by 2;
            if(trailingZeroInFactorial(mid)>=q)
                high=mid;
            else
                low=mid+1;
        }
    return low;
}
int main()
{
    int t=100;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<smallestNum(n)<<endl;
    }

}
