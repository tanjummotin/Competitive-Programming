///in the name of ALLAH
///Tutorial:https://shikhorroy.wordpress.com/2014/02/22/wp-mep2mliv-6g/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 ll FactorialPrimePower(ll n,ll p)///How many times prime p occur in n!
 {

         ll x=n;
         ll freq =0;
         while(x)
         {
             freq+=x/p;
             x=x/p;
         }
        return freq;

 }
 ll PrimePower(ll n,ll p)///How many times a prime occur in n
 {

         ll freq =0;
         while(n%p==0)
         {
             freq++;
             n=n/p;

         }
        return freq;
 }
int main()
{
    int t;
    scanf("%d",&t);
    for(int te=1;te<=t;te++)
    {
        ll n,r,p,q,i,j,k,l,m,o,x,y;
        scanf("%lli%lli%lli%lli",&n,&r,&p,&q);
        ///nCr=n!/(r!*(n-r)!)
        i=FactorialPrimePower(n,2);
        j=FactorialPrimePower(n,5);
        k=FactorialPrimePower(r,2);
        l=FactorialPrimePower(r,5);
        m=FactorialPrimePower(n-r,2);
        o=FactorialPrimePower(n-r,5);
        ///p^q
        x=q*PrimePower(p,2);
        y=q*PrimePower(p,5);
       ll numOf2=i-k-m+x;
       ll numOf5=j-l-o+y;
       ll ans=min(numOf2,numOf5);
       printf("Case %d: %lli\n",te,ans);


    }

}
