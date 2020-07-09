///in the name of ALLAH
///Tutorial:https://forthright48.com/prime-factorization-of-factorial/
///How many times a prime p occurs in n!
#include<bits/stdc++.h>
#define mx 32000
using namespace std;
typedef long long ll;
 vector<ll>prime;
 vector<ll>factors;
 void sieve()
 {
     bool flag[mx];
     memset(flag,0,sizeof(flag));
     flag[1]=1;
     for(int i=4;i<=mx;i+=2)
    {
        flag[i]=1;
    }
     for(int i=3;i<=sqrt(mx);i+=2)
     {
         if(flag[i]==0)
         {
             for(int j=2*i;j<=mx;j+=i)
                flag[j]=1;
         }
     }
     for(int i=2;i<mx;i++)
     {
         if(flag[i]==0)
         {
             prime.push_back(i);
         }
     }
     //for(int i=0;i<10;++i)
        //cout<<prime[i]<<endl;
 }
 ll FactorialPrimePower(ll n,ll p)
 {

         ll x=n;
         ll freq =0;
         while(x)
         {
             freq+=x/p;
             x=x/p;
             cout<<x<<endl;
         }
        return freq;

 }
int main()
{
    ll n,p;
    cin>>n>>p;
    sieve();
    n=9*1e18;
    cout<<FactorialPrimePower(n,p)<<endl;
}
