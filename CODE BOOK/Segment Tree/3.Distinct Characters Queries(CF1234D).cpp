///BISMILLAHIR RAHMANIR RAHIM
/*There are two types of queries:
1 pos c (1≤pos≤|s|, c is lowercase Latin letter): replace s[pos] with c (set spos:=c);
2 l r (1≤l≤r≤|s|): calculate the number of distinct characters in the substring s[l;r].
*/
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
string s;
const ll mx=100005;

struct Node
{
    ll Count[27];
    Node()
    {
        for(int i=0; i<27; i++)
            Count[i]=0;
    }

} tree[3*mx];

void init(ll node,ll b,ll e)
{
    if(b==e)///leaf node
    {
        tree[node].Count[s[b]-'a']++;
        return;
    }
    ll left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    ll dis=0;
    for(int i=0; i<27; i++)
    {
        tree[node].Count[i]=tree[left].Count[i]+tree[right].Count[i];
    }
    return;

}

bitset<27> query(ll node,ll b,ll e,ll i,ll j)
{
    bitset<27>bs,bs1,bs2;
    if(i>e || j<b)
        return bs;
    if(b>=i && e<=j)
    {
        for(int i=0; i<27; i++)
        {
            if(tree[node].Count[i]>0)
            {
                bs[i]=1;
            }
        }
        return bs;
    }
    ll left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    bs1=query(left,b,mid,i,j);
    bs2=query(right,mid+1,e,i,j);
    for(int i=0; i<27; i++)
    {
        if(bs1[i]||bs2[i])
        {
            bs[i]=1;
        }
    }
    return bs;

}
void update(ll node,ll b,ll e,ll pos,char new_value)
{
    if(pos>e || pos<b)
        return;
    if (b == e && e==pos)
    {
        tree[node].Count[s[pos]-'a']--;
        s[pos]=new_value;
        tree[node].Count[s[pos]-'a']++;
        return;
    }
    ll left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    if(pos<=mid)
    update(left,b,mid,pos,new_value);
    else
    update(right,mid+1,e,pos,new_value);
    ll dis=0;
    for(int i=0; i<27; i++)
    {
        tree[node].Count[i]=tree[left].Count[i]+tree[right].Count[i];
    }
    return;
}
int main()
{
    fastio;
    cin>>s;
    init(1,0,s.size()-1);
    ll q,p,l,r,pos;
    char ch;
    cin>>q;
    while(q--)
    {
        cin>>p;
        if(p==1)
        {
          cin>>pos>>ch;
          pos--;
          update(1,0,s.size()-1,pos,ch);
          //cout<<s<<endl;
        }
        else if(p==2)
        {
            cin>>l>>r;
            l--;
            r--;
            bitset<27>ans=query(1,0,s.size()-1,l,r);
            int c=0;
            for(int i=0;i<27;i++)
            {
                if(ans[i])c++;
            }
            cout<<c<<endl;
        }
    }
}

