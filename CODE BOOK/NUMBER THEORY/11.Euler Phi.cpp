///in the name of ALLAH
///Euler Phi/Euler totient function=>count number of co-prime of n from 1 to n
///Tutorial:https://cp-algorithms.com/algebra/phi-function.
///https://www.youtube.com/watch?v=u8xQUtxUJeg
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll eulerPhi(ll n)
{
    ll result=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
                n/=i;
            result-=result/i;
        }
    }
    if(n>1)
        result-=result/n;
    return result;
}
int main()
{
    ll n;
    cin>>n;
    cout<<eulerPhi(n)<<endl;

}
