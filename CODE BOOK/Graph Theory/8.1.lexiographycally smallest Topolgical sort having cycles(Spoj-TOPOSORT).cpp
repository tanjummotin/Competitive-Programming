///BISMILLAHIR RAHMANIR RAHIM
///https://www.spoj.com/problems/TOPOSORT/
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
vector<ll>res;
vector<ll>adj[10005];
ll in[10005];
bool Kahn(int n)
{
    priority_queue<int, vector<int>, greater<int>>q;
    for(int i=1; i<=n; i++)
    {
        if(in[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int cur=q.top();
        res.push_back(cur);
        q.pop();
        for(int i=0; i<adj[cur].size(); i++)
        {
            int u=adj[cur][i];
            in[u]--;
            if(in[u]==0)
                q.push(u);
        }
    }
    if(res.size()==n)
        return 1;
    else
        return 0;

}
int main()
{
    fastio;
    int n,m,x,y;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        in[y]++;
    }
    if(Kahn(n))
    {
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    else ///Graph has cycles
        cout<<"Sandro fails."<<endl;
}




