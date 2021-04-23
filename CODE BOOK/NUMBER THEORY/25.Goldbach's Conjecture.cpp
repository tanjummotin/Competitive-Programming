///In the name of ALLAH
///For any integer n (n ≥ 4) there exist two prime numbers p1 and p2 such that p1 + p2 = n
#include<bits/stdc++.h>
#define mx 1000000
using namespace std;
typedef long long ll;
vector<ll>prime;
bool flag[mx];
 void sieve()
 {

     memset(flag,0,sizeof(flag));
     flag[1]=1;
     for(int i=4;i<mx;i+=2)
    {
        flag[i]=1;
    }
     for(int i=3;i<=sqrt(mx);i+=2)
     {
         if(flag[i]==0)
         {
             for(int j=2*i;j<mx;j+=i)
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
void goldbachs_conjecture(ll n)
{

    ll x,y;
    bool f=0;
    for(ll i=2; i<=n/2; i++)
    {
        if(flag[i]==0 && flag[n-i]==0)
        {
            x=i;
            y=n-i;
            f=1;
            break;
        }
    }
    if(f==1)
    {
        printf("%lli = %lli + %lli\n",n,x,y);
    }
    else
        printf("Impossible.\n");
}
 int main()
 {
     sieve();
     ll n;
     cin>>n;
     goldbachs_conjecture(n);
 }

