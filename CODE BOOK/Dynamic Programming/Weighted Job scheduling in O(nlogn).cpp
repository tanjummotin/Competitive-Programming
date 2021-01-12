///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    ll startTime[n],endTime[n],profit[n],ans[n];
    vector<pair<ll,ll> >v;
    map<pair<ll,ll>,ll>m;
    for(int i=0;i<n;i++)
    {
        cin>>startTime[i]>>endTime[i]>>profit[i];
        v.push_back(make_pair(startTime[i],endTime[i]));
        m[make_pair(startTime[i],endTime[i])]=profit[i];
    }
    sort(startTime,startTime+n);
    sort(v.begin(),v.end());
   /*for(int i=n-1;i>=0;i--)
   {
       cout<<v[i].first<<" "<<v[i].second<<endl;
   }*/
    for(int i=n-1;i>=0;i--)
    {
        ll x=v[i].second;
        int l=lower_bound(startTime,startTime+n,x)-startTime;
        ans[i]=m[make_pair(v[i].first,v[i].second)];
        if(l!=n)
        {
           ans[i]+=ans[l];
        }
        cout<<ans[i]<<endl;
       if(i!=n-1){
        ans[i]=max(ans[i+1],ans[i]);
        }
    }
    cout<<ans[0]<<endl;
}
