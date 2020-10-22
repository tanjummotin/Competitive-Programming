///in the name of ALLAH
#include<bits/stdc++.h>
#define mx 3000001
using namespace std;
typedef uint64_t ll;
ll phi[mx];
ll res[mx];
ll mod=2e64;
//ll sum[mx];
void phi_1_to_n( )
{
    for(int i=0;i<mx;i++)phi[i]=i;
    for(int i=2;i<mx;i++)
    {
        if(phi[i]==i)///a prime
        {
            for(int j=i;j<mx;j+=i)
            {
                phi[j]-=phi[j]/i;
            }
        }
    }
}
void precalculate_ans()
{
    for(int i=1;i<mx;i++)
    {
        for(int j=i;j<mx;j+=i)
        {
            res[j]+=phi[i]*i;
        }
    }
    //sum[0]=0;
    res[0]=0;
    for(int i=1;i<mx;i++)
    {
        //sum[i]=sum[i-1]+(((res[i]+1)*i)/2-i);
        ll x=(((res[i]+1)/2)*i)-i;
        res[i]=(res[i-1]%mod+x%mod)%mod;
           // ans[i]=ans[i-1]+sum[i];
    }

}
int main()
{
    phi_1_to_n();
    precalculate_ans();

    long long int t,n,te;
    scanf("%lli",&t);
    for( te=1;te<=t;te++)
    {
        scanf("%lli",&n);
        printf("Case %lli: %" PRIu64 "\n",te,res[n]%mod);

    }
}

