///in the name of ALLAH
///Tutorial:https://forthright48.com/prime-factorization-of-factorial/
///Prime factorization of factorial
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
 void FactFactorize(int n)
 {
     for(int i=0;i<prime.size() && prime[i]<=n;i++)
     {
         ll p=prime[i];
         ll freq =0;
         ll x=n;
         while(x/p)
         {
             freq+=x/p;
            x=x/p;
         }
         cout<<prime[i]<<" "<<freq<<endl;
     }
 }
int main()
{
    ll n;
    cin>>n;
    sieve();
    FactFactorize(n);
}
