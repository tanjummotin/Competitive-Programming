///BISMILLAHIR RAHMANIR RAHIM
///Complexity:O(VlogV+E) V->node,E->edge
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INF 1000000000000000000
#define pii pair<ll,ll>
using namespace std;
typedef long long ll;
vector<pair<int,int> > adj[100001];
vector<ll>parent(100001,-1);
ll n;
/// vector dis contains distance from source to all other nodes
/// vector parent contains path to it's parent in the shortest path (except for root, source)
void Dijkstra(ll source)
{
    vector<ll>dist(n+1,INF);
    priority_queue<pii,vector<pii>,greater<pii> >pq;
    pq.push({0,source});
    dist[source]=0;
    while(!pq.empty())
    {
        ll v=pq.top().second;
        ll v_dis=pq.top().first;
        pq.pop();
        if(v_dis!=dist[v])
            continue;
        for(int i=0;i<adj[v].size();i++)
        {
             ll p=adj[v][i].first;
              ll q=adj[v][i].second;
            if(v_dis+q<dist[p])
            {
                dist[p]=v_dis+q;
                parent[p]=v;
                pq.push({dist[p],p});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {

            cout<<dist[i]<<" ";
    }
    cout<<endl;
}
void printPath(ll j)
{
    if(parent[j]==-1)///If j is source
    {
        cout<<1<<" ";
        return;
    }
        printPath(parent[j]);
        cout<<j<<" ";

}

int main()
{
   ll m,a,b,w;
   cin>>n>>m;  ///n->node,m->edge
   while(m--)
   {
       cin>>a>>b>>w; ///a ,b node r maje edge ache w weight r
       adj[a].push_back({b,w});
       adj[b].push_back({a,w});///bidirectional graph hoate
   }
   Dijkstra(1);
   /// 1 teke n node r shortest path
   cout<<"1 teke n node r shortest path--> ";
   printPath(n);
   cout<<endl;

}


