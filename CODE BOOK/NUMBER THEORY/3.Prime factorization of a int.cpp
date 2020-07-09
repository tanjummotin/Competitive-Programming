///in the name of ALLAH
///Tutorial:https://forthright48.com/prime-factorization-of-integer/
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
 void factorize(ll n)
 {
     ll sqrtn=sqrt(n);
     for(int i=0;i<prime.size()&& prime[i]<=sqrtn;i++)
     {
         if(n%prime[i]==0)
         {
             while(n%prime[i]==0)
             {
                 n/=prime[i];
                 factors.push_back(prime[i]);
             }
             sqrtn=sqrt(n);
         }
     }
     if(n!=1)
     {
         factors.push_back(n);
     }
 }
int main()
{
    ll n;
    cin>>n;
    sieve();
    factorize(n);
    for(int i=0;i<factors.size();i++)
    {
        cout<<factors[i]<<" ";
    }
}
