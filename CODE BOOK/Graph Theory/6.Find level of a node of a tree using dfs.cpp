///in the name of ALLAH
#include<bits/stdc++.h>
#define mx 100005
using namespace std;
typedef long long ll;
vector<ll>adj[mx];
bool visited[mx];
ll level[mx];
void dfs(ll u)
{
    visited[u]=1;
    for(int i=0;i<adj[u].size();i++)
    {
        ll v=adj[u][i];
        if(visited[v]!=1){
        level[v]=level[u]+1;
        dfs(v);
        }
    }
}
int main()
{
    ll node,edge,x,y;
    cin>>node>>edge;
    for(int i=0;i<edge;i++)///storing time complexity-O(edge)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    level[1]=0;
    dfs(1);
    for(int i=1;i<=node;i++)
        cout<<"level of "<<i<<" "<<level[i]<<endl;



}

