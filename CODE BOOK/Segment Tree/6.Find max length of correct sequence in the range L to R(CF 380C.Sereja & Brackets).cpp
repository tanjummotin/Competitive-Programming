///BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
string s;
const ll mx=1000005;

struct Node
{
    ll ans,lb,rb;
    node()
    {
        ans=0;lb=0;rb=0;
    }
} tree[4*mx];

void init(ll node,ll b,ll e)
{
    if(b==e)///leaf node
    {
        if(s[b]=='(')
        {
            tree[node].lb=1;
        }
        else
        {
            tree[node].rb=1;
        }
        return;
    }
    ll left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    ll match=min(tree[left].lb,tree[right].rb);
    tree[node].ans=tree[left].ans+tree[right].ans+match;
    tree[node].lb=tree[left].lb+tree[right].lb-match;
    tree[node].rb=tree[left].rb+tree[right].rb-match;
    return;

}

Node query(ll node,ll b,ll e,ll i,ll j)
{
    //cout<<b<<" "<<e<<endl;
    Node p3;
    if(i>e || j<b)
    {
        p3.ans=0;p3.lb=0;p3.rb=0;
        return p3;
    }
    if(b>=i && e<=j)
    {
        //cout<<node<<" "<<b<<" "<<e<<" "<<tree[node].ans<<endl;
        return tree[node];
    }
    ll left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
   Node p1=query(left,b,mid,i,j);
   Node p2=query(right,mid+1,e,i,j);
    ll match=min(p1.lb,p2.rb);
    p3.ans=p1.ans+p2.ans+match;
    p3.lb=p1.lb+p2.lb-match;
    p3.rb=p1.rb+p2.rb-match;
    return p3;
}
int main()
{
    fastio;
    cin>>s;
    ll n=s.size();
    init(1,0,n-1);
    ll q,l,r;
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        l--;
        r--;
        cout<<2*(query(1,0,n-1,l,r).ans)<<endl;
    }
}




