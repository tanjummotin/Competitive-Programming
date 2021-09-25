///BISMILLAHIR RAHMANIR RAHIM
///Graph doesn't contain cycles
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
vector<ll>res;
vector<ll>adj[100];
ll in[100];
void Kahn(int n)
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int cur=q.front();
        res.push_back(cur);
        q.pop();
         for(int i=0;i<adj[cur].size();i++)
         {
             int u=adj[cur][i];
             in[u]--;
             if(in[u]==0)
                q.push(u);
         }
    }
    cout<<"Topological sort: ";
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    cout<<endl;
}
int main()
{
    fastio;
    int n,m,x,y;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        in[y]++;
    }
    Kahn(n);
}
/*
9 10
1 2
3 4
1 8
2 9
2 5
4 5
4 8
5 9
5 7
6 7
Topological sort: 1 3 6 2 4 5 8 9 7
*/


