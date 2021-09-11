///BISMILLAHIR RAHMANIR RAHIM
///Given an array size N and Q queries of form L R K,find elements int the range L o R which are greater than K
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
const ll mx=30005;
vector<ll> tree[4*mx];
ll arr[mx];
void init(ll node,ll b,ll e)
{
    if(b==e)///leaf node
    {
        tree[node].push_back(arr[b]);
        return;
    }
    ll left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    int i=0,j=0;
    while(i<tree[left].size() && j<tree[right].size())
    {
        if(tree[left][i]<=tree[right][j])
        {
            tree[node].push_back(tree[left][i]);
            i++;
        }
        else
        {
            tree[node].push_back(tree[right][j]);
            j++;
        }
    }
    while(i<tree[left].size())
    {
        tree[node].push_back(tree[left][i]);
        i++;
    }
    while(j<tree[right].size())
    {
        tree[node].push_back(tree[right][j]);
        j++;
    }

}
ll query(ll node,ll b,ll e,ll i,ll j,ll k)
{
    if(i>e || j<b)
        return 0;
    if (b >= i && e <= j)
    {
        ll x=upper_bound(tree[node].begin(),tree[node].end(),k)-tree[node].begin();
       ll res=tree[node].size()-x;
        return res;
    }
    ll left,right,mid,p1,p2;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    p1=query(left,b,mid,i,j,k);
    p2=query(right,mid+1,e,i,j,k);
    return p1+p2;

}
int main()
{
    fastio;
    ll q,l,r,k,n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    init(1,0,n-1);
    cin>>q;
    while(q--)
    {
        cin>>l>>r>>k;
        l--;r--;
        cout<<query(1,0,n-1,l,r,k)<<endl;
    }
}


