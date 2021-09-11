//in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define mx 100005
typedef long long ll;
ll arr[mx];
ll tree[mx*3];

void init(ll node,ll b,ll e)
{
    if(b==e)//leaf node
    {
        tree[node]=arr[b];
        return;
    }
    ll left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

ll query(ll node,ll b,ll e,ll i,ll j)
{
    if(i>e || j<b)
        return 0;
     if (b >= i && e <= j)
        return tree[node];
        ll left,right,mid,p1,p2;
        left=node*2;
        right=node*2+1;
        mid=(b+e)/2;
        p1=query(left,b,mid,i,j);
        p2=query(right,mid+1,e,i,j);
        return p1+p2;

}

void update(ll node,ll b,ll e,ll i,ll new_value)
{
    if(i>e || i<b)
        return;
     if (b == e && e==i) {
        tree[node] = new_value;
        return;}
    ll left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    update(left,b,mid,i,new_value);
    update(right,mid+1,e,i,new_value);
    tree[node]=tree[left]+tree[right];
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    init(1,1,n);
    cout<<query(1,1,n,1,3)<<endl;
    update(1,1,n,2,0);
    cout<<query(1,1,n,1,3)<<endl;
    update(1,1,n,2,2);
    cout<<query(1,1,n,2,2)<<endl;

}
