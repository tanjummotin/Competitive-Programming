///in the name of ALLAH
#include<bits/stdc++.h>
#define mx 100005
using namespace std;
typedef long long ll;
vector<ll>adj[mx];
bool visited[mx];
void dfs(ll u)
{
    visited[u]=1;
    for(int i=0;i<adj[u].size();i++)
    {
        ll v=adj[u][i];
        if(visited[v]!=1)
        dfs(v);
    }
}
int main()
{
    ll node,edge,x,y,comp=0;
    cin>>node>>edge;
    for(int i=0;i<edge;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=node;i++)
    {
        if(visited[i]==0)
        {
            comp++;
            dfs(i);
        }
    }
    cout<<comp<<endl;

}

