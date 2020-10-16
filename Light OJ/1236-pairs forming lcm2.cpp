///in the name of ALLAH
#include<bits/stdc++.h>
#define mx 10000005
using namespace std;
typedef uint64_t ll;
vector<ll>prime;
 bool flag[mx];
void sieve()
 {
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
int main()
{
    sieve();
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
