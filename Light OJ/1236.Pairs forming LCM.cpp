///in the name of ALLAH
#include<bits/stdc++.h>
#define mx 10000005
using namespace std;
typedef uint64_t ll;
 int status[mx/32+2];
vector<ll>prime;
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
    prime.push_back(2);
    for(int i=3;i<=mx;i+=2)
    {
        if(check(status[i>>5],i&31)==0)
            prime.push_back(i);
    }

}
int main()
{
    bitwise_sieve();
    int t;
    scanf("%d",&t);
    for(int te=1;te<=t;te++)
    {
        ll n,c,ans=1;
        cin>>n;
        for(int i=0;i<prime.size() && prime[i]<=sqrt(n);i++)
        {
            if(n%prime[i]==0)
            {c=0;
                while(n%prime[i]==0)
                {
                    n/=prime[i];
                    c++;
                }
                ans*=(2*c+1);
                //cout<<prime[i]<<" "<<c<<" "<<ans<<endl;
            }
        }
        if(n!=1)
        {
            ans*=3;
        }
        //cout<<ans<<endl;
        ans=(ans/2)+1;
        cout<<"Case "<<te<<": "<<ans<<endl;

    }
}
