///in the name of ALLAH
///Tutorial:https://cp-algorithms.com/algebra/divisors.html
///https://www.geeksforgeeks.org/total-number-divisors-given-number/
#include<bits/stdc++.h>
#define mx 1000000
using namespace std;
typedef long long ll;
 vector<ll>prime;
 ll bigmod(ll a,ll b)
{
    if(b==0)
        return 1;
    ll x=bigmod(a,b/2);
    x=(x*x);
    if(b%2==1)
        x=(x*a);
    return x;
}
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
ll SumOfDivisors(ll n)
 {
     ll sqrtn=sqrt(n);
     ll c=0,ans=1;
     for(int i=0;i<prime.size()&& prime[i]<=sqrtn;i++)
     {
         if(n%prime[i]==0)
         {c=0;
             while(n%prime[i]==0)
             {
                 n/=prime[i];
                 c++;
             }
             sqrtn=sqrt(n);
             ans*=((bigmod(prime[i],c+1)-1)/(prime[i]-1));
         }
     }

     if(n!=1 )
     {
         ans*=((bigmod(n,2)-1)/(n-1));
     }
     return ans;
 }
int main()
{
    sieve();

        ll n;
        scanf("%lli",&n);
        printf("%lli\n",SumOfDivisors(n));
}


