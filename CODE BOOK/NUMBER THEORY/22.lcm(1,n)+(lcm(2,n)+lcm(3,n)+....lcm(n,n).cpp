///in the name of ALLAH
///Problem:calculate the sum LCM(1,n) + LCM(2,n) + .. + LCM(n,n)
///Tutorial:https://www.youtube.com/watch?v=SKBjnm39Puk&t=210s
///https://forthright48.com/spoj-lcmsum-lcm-sum/  && note book
#include<bits/stdc++.h>
#define mx 1000005
using namespace std;
typedef uint64_t ll;
ll phi[mx];
ll res[mx];
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
    for(int i=1;i<=mx;i++)
    {
        for(int j=i;j<=mx;j+=i)
        {
            res[j]+=phi[i]*i;
        }
    }
}
int main()
{
    phi_1_to_n();
    precalculate_ans();
    //for(int i=1;i<=10;i++)
        //cout<<phi[i]<<" "<<res[i]<<endl;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,ans;
        cin>>n;
        ans=((res[n]+1)*n)/2;
        cout<<ans<<endl;

    }
}
