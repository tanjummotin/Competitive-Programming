//in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
#define mx 100005
typedef long long ll;
ll arr[mx];
struct info{

    ll prop,sum;
};
info tree[mx*4];
void init(ll node,ll b,ll e)
{
    if(b==e)//leaf node
    {
        tree[node].sum=arr[b];
        return;
    }
    ll left,right,mid;
    left=node<<1;
    right=(node<<1)+1;
    mid=(b+e)>>1;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
}

void update(ll node,ll b,ll e,ll i,ll j,ll x)
{
    if(i>e || j<b)
        return;
     if (b>=i && e<=j) {
        tree[node].sum += (e-b+1)*x;
        tree[node].prop+=x;
        return;
        }
        ll left,right,mid;
        left=node<<1;
        right=(node<<1)+1;
        mid=(b+e)>>1;
        update(left,b,mid,i,j,x);
        update(right,mid+1,e,i,j,x);
        tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;

}

ll query(ll node,ll b,ll e,ll i,ll j,ll carry=0)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node].sum+carry*(e-b+1);
    ll left,right,mid,p1,p2;
    left=node<<1;
    right=(node<<1)+1;
    mid=(b+e)>>1;
    p1=query(left,b,mid,i,j,carry+tree[node].prop);
    p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
}

int main()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
        init(1,1,n);
        update(1,1,n,1,7,2);
        cout<<query(1,1,n,1,4)<<endl;
        cout<<query(1,1,n,1,1)<<endl;



}
