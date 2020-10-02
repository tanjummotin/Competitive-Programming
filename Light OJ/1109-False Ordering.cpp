///in the name of ALLAH
#include<bits/stdc++.h>
#define mx 1005
using namespace std;
typedef long long ll;
vector<ll>prime;
void sieve()
{
    bool flag[mx];
    memset(flag,0,sizeof(flag));
    flag[1]=1;
    for(int i=4; i<=mx; i+=2)
    {
        flag[i]=1;
    }
    for(int i=3; i<=sqrt(mx); i+=2)
    {
        if(flag[i]==0)
        {
            for(int j=2*i; j<=mx; j+=i)
                flag[j]=1;
        }
    }
    for(int i=2; i<mx; i++)
    {
        if(flag[i]==0)
        {
            prime.push_back(i);
        }
    }
    //for(int i=0;i<10;++i)
    //cout<<prime[i]<<endl;
}
ll NumOfDivisors(ll n)
{
    ll sqrtn=sqrt(n);
    ll c=0,ans=1;
    for(int i=0; i<prime.size()&& prime[i]<=sqrtn; i++)
    {
        if(n%prime[i]==0)
        {
            c=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                c++;
            }
            sqrtn=sqrt(n);
            ans*=(c+1);
        }
    }

    if(n!=1 )
    {
        ans*=2;
    }
    return ans;
}
int main()
{
    sieve();
    vector<pair<int,int> >v;
    vector<ll>ve;
    map<int,int>m;
    ve.push_back(0);
    for(int i=1; i<=1000; i++)
    {
        //v.push_back(make_pair(NumOfDivisors(i),i));
        m[i]=NumOfDivisors(i);
        ve.push_back(i);
        //cout<<m[i]<<" ";
    }
    //cout<<endl<<endl;
    //sort(v.begin(),v.end());
    ll c=0;
    //cout<<"ve"<<ve[1]<<endl;
    for(int i=1; i<1000; i++)
    {
        for(int j=i+1; j<=1000; j++)
        {

            if(m[ve[i]]==m[ve[j]] && ve[j]>ve[i])
            {
                //if(i==1)
                //cout<<m[ve[i]]<<" "<<m[ve[j]]<<" "<<ve[i]<<" "<<ve[j]<<"in"<<endl;
                swap(ve[i],ve[j]);

            }
            else if(m[ve[i]]>m[ve[j]] )
            {
                //if(i==1)
                    //cout<<m[i]<<" "<<m[j]<<"in1"<<endl;
                swap(ve[i],ve[j]);

            }
        }
    }
    ll p;
    /* for(int i=1;i<=1000;i++)
     {
         c++;
         cout<<ve[i]<<" ";

     }
     cout<<endl;*/

    int t;
    cin>>t;
    for(int te=1; te<=t; te++)
    {
        int n;
        cin>>n;
        cout<<"Case "<<te<<": "<<ve[n]<<endl;

    }

}

