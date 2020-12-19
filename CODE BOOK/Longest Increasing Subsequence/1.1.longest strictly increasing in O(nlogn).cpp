///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
///lis in nlogn

void lis()
{
    ll n,x;
    cin>>n;
    vector<ll>v;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        int l=lower_bound(v.begin(),v.end(),x)-v.begin();
        if(l==v.size())
            v.push_back(x);
        else
            v[l]=x;
    }
    cout<<v.size()<<endl;
}
int main()
{
    lis();

}
