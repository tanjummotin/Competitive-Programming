///BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mx 200005
vector<ll>adj[mx];
ll visited[mx],color[mx],red,black;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
bool isbipartite(ll u)
{
    queue<ll>q;
    q.push(u);
    color[u]=0;
    visited[u]=1;
    red++;
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        //visited[u]=1;
        //cout<<"in----------"<<u<<endl;

        for(ll i=0; i<adj[u].size(); i++)
        {
            ll v=adj[u][i];
            if(visited[v]==0)
            {
                if(color[v]==-1)
                {
                    color[v]=1-color[u];
                    //cout<<"color "<<v<<" "<<color[v]<<endl;
                    if(color[v]==0)red++;
                    else black++;
                }
                else
                {
                    if(color[u]==color[v])return false;
                }

                visited[v]=1;
                q.push(v);
            }
            else
            {
                if(color[u]==color[v])return false;
            }
        }
    }
    return true;

}
int main()
{
    fastio;
    ll n,m,u,v;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0; i<mx; i++)
    {
        color[i]=-1;
    }
    if(isbipartite(1))
    {
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;


}

