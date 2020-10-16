///in the name of ALLAH
#include<bits/stdc++.h>
#define mx 100000005
using namespace std;
typedef unsigned ll;
ll status[mx/32+2];
//ll mod=4294967296;
 ll prime[5761455+5];
ll mul[5761455+5];///number of prime upto mx is 5761455
ll c=1;
ll bigmod(ll a,ll b)
{
    //uint64_t m=4294967296;
    if(b==0)
        return 1;
    ll x=bigmod(a,b/2);
    x=(x*x);
    if(b%2==1)
        x=(x*a);
    return x;
}
bool check(int n,int pos)
{
    return n & (1<<pos);
}
int Set(int n,int pos)
{
    n=n | (1<<pos);
    return n;
}
void bitwise_sieve()
{
    int i,j,sqrtMx;
    sqrtMx=sqrt(mx);
    for(int i=3;i<=sqrtMx;i+=2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            for(j=i*i;j<=mx;j+=(i<<1))///j+=(i<<1) => j+=2*i
            {
                status[j>>5]=Set(status[j>>5],j&31);
            }
        }
    }
    prime[0]=2;

    for(int i=3;i<=mx;i+=2)
    {
        if(check(status[i>>5],i&31)==0)
            {
                prime[c]=i;
                c++;
            }
    }

}
void prime_mul()
{
    mul[0]=2;
    for(int i=1;i<5761460;i++){
        mul[i]=(mul[i-1]*prime[i]);
        //cout<<mul[i]<<" ";
    }
}
int main()
{
    bitwise_sieve();
    prime_mul();
   int t;
   scanf("%d",&t);
   for(int te=1;te<=t;te++)
   {
       int n;
       scanf("%d",&n);
       ll ans=1,temp;
       for(int i=0;prime[i]<=sqrt(n);i++)
       {
           temp=n/prime[i];
           while(temp>=prime[i])
           {
               ans*=prime[i];
               temp/=prime[i];
           }
       }
       ll u=upper_bound(prime,prime+c,n)-prime;
       //cout<<u<<endl;
       //cout<<mul[u-1]<<endl;
       ans=(ans*mul[u-1]);
       cout<<"Case "<<te<<": "<<ans<<endl;
   }
}




