///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll bigmod(ll a,ll b)
{
    if(b==0)
        return 1;
    ll x=bigmod(a,b/2);
    x=(x*x);
    if(b%2==1)
        x=(x*a);
    return x;
}
int  main()
{
    int t;
    scanf("%d",&t);
    for(int te=1; te<=t; te++)
    {
        ll n,n1,num1=0,r,ans=0;
        scanf("%lli",&n);
        n1=n;
        string s1="",s2="";
        while(n1>0)
        {
            r=n1%2;
            if(r==0)
                s1+="0";
            else
            {
                s1+="1";
                num1++;
            }
            n1/=2;
        }
        reverse(s1.begin(),s1.end());
        //cout<<s1<<endl;
        s2=s1;
        sort(s2.begin(),s2.end());
        reverse(s2.begin(),s2.end());
        //cout<<s2<<endl;
        if(s2==s1)
        {
            ans=bigmod(2,s1.size())+bigmod(2,num1-1)-1;
        }
        else
        {
            ll c=-1;
            bool f=0;
            /*for(int i=s1.size()-1; i>=0; i--)
            {
                c++;
                if( i!=0 && s1[i]=='1' && s1[i-1]=='0' && f==0)
                {
                    swap(s1[i],s1[i-1]);
                    string x=s1.substr()
                    cout<<s1[i]<<" "<<s1[i-1]<<endl;
                    f=1;
                }
                if(s1[i]=='1')
                    ans+=bigmod(2,c);
                    cout<<ans<<endl;

            }*/
            reverse(s1.begin(),s1.end());
            for(int i=0; i<s1.size(); i++)
            {
                if(i!=s1.size()-1 && s1[i]=='1' && s1[i+1]=='0' && f==0)
                {
                    swap(s1[i],s1[i+1]);
                    f=1;
                    sort(s1.begin(),s1.begin()+i+1);
                    reverse(s1.begin(),s1.begin()+i+1);
                    break;
                }
            }
            //cout<<s1<<endl;
            for(int i=0; i<s1.size(); i++)
            {
                if(s1[i]=='1')
                    ans+=bigmod(2,i);
            }
            {

            }
        }
        printf("Case %d: %lli\n",te,ans);
    }
}
