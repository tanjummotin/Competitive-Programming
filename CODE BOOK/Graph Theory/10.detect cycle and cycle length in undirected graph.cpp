///BISMILLAHIR RAHMANIR RAHIM
///cf 1702E
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mx 200005
using namespace std;
typedef long long ll;
vector<int>adj[mx];
bool visited[mx];
ll len;

bool dfs(int u,int par)
{
    visited[u]=1;
    len++;
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(visited[v]!=1)
        {
            if(dfs(v,u))
                return true;
        }
        else///Check back edge
        {
           if(v!=par)
                return true;
        }

    }
    return false;
}
int main()
{
    fastio;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,a,b;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            visited[i]=0;
            adj[i].clear();
        }
        bool mf=1;
        map<ll,ll>mp;
        for(ll i=1; i<=n; i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
           mp[a]++;
           mp[b]++;
           if(mp[a]>2 || mp[b]>2)
            mf=0;
            if(a==b)
            {
                mf=0;
            }

        }
        if(mf==0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            for(ll i=1; i<=n; i++)
            {

                  if(visited[i]==0)
                  {//cout<<i<<" cycle "<<detectCycle(i)<<endl<<"len "<<len<<endl;
                      //cout<<i<<endl;
                      len=0;
                      if((dfs(i,-1)==1) && (len%2!=0))
                      {
                          //cout<<" len "<<len<<endl;
                          mf=0;break;
                      }
                     // cout<<endl;
                  }

            }
            if(mf==0)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
    }
}


 
