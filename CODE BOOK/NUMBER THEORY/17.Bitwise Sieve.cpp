///in the name of ALLAH
///Tutorial:https://codeforces.com/blog/entry/73490
#include<bits/stdc++.h>
#define mx 100000005
using namespace std;
typedef long long ll;
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
   // for(int i=0;i<prime.size();i++)
       // cout<<prime[i]<<" ";
        cout<<prime.size();
    cout<<endl;

}

