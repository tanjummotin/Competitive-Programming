///in the name of ALLAH
#include<bits/stdc++.h>
#define mx 32000
using namespace std;
typedef long long ll;
 vector<int>prime;
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
 void segsieve(ll l,ll r)
 {
     bool pri[r-l+1];
     ll cupri,base;
     memset(pri,0,sizeof(pri));
    if(l==1)
        pri[0]=1;
     for(int i=0;prime[i]*prime[i]<=r;i++)
     {//cout<<"in2"<<endl;
         cupri=prime[i];
         base=(l/cupri)*cupri;
         if(base<l)
            base +=cupri;
         for(ll j=base;j<=r;j+=cupri)
         {
             pri[j-l]=1;
         }
         if(base==cupri)
            pri[base-l]=0;
     }
     for(int i=0;i<r-l+1;i++)
     {
         if(pri[i]==0)
            cout<<i+l<<endl;
     }
 }
int main()
{
   int t;
   cin>>t;
   sieve();
  for(int k=1;k<=t;k++)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll m,n;
        scanf("%lli%lli",&m,&n);

        segsieve(m,n);
        //sieve();
        if(k!=t)
            cout<<endl;
    }
    return 0;


}




