///BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
const int mx=200005;
vector<pair<int,pair<int,int> > >gr;
int parent[mx];
int node,edge;
int find_parent(int n) ///kono node r parent ber kore/akta point kon set e ber korce
{
    if(parent[n]==n)
        return n;
    else
        return  parent[n]=find_parent(parent[n]);
}
void union_(int u,int v)///2 ta set/node ke merge kore
{
    int par_u=find_parent(u);
    int par_v=find_parent(v);
    parent[par_u]=par_v;
}
ll MST()
{
    int i=0,co=0;
    ll cost=0;
   while(co!=node-1)
   {
       int p1=find_parent(gr[i].second.first);
       int p2=find_parent(gr[i].second.second);
       ///two nodes do not form a cycle
       if(p1!=p2)
       {
           union_(gr[i].second.first,gr[i].second.second);
           co++;
           cost+=gr[i].first;
       }

       i++;
   }
   return cost;
}
int main()
{
    fastio;
    ll t;
    cin>>t;
    while(t--)
    {
      cin>>node>>edge;
      for(int i=0;i<edge;i++)
      {
          int a,b,c;
          cin>>a>>b>>c;
          gr.push_back({c,{a,b}});
      }
      sort(gr.begin(),gr.end());
      for(int i=1;i<=node;i++)
      {
          parent[i]=i;
      }
      cout<<MST()<<endl;
    }
}

