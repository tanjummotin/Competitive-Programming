///in the name of ALLAH
///Graph representation using adjacency list
///Tutorial:
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll node,edge;
    cin>>node>>edge;
    vector< pair<ll,ll> >v[node];
    for(int i=0;i<edge;i++)
    {
        ll source;
        pair<ll,ll>p;
        cin>>source>>p.first>>p.second;
        v[source].push_back(p);
        ll s2=p.first;
        p.first=source;
        v[s2].push_back(p);

    }
    for(int i=0;i<node;i++)
    {
        cout<<i<<" -- ";
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j].first<<"-"<<v[i][j].second<<"  ";
        cout<<endl;
    }
}
///Bidirectional graph
/*
8 9
0 3 3
0 4 6
1 5 5
1 6 1
2 4 6
3 5 8
5 6 3
5 7 2
6 7 6
0 -- 3-3  4-6
1 -- 5-5  6-1
2 -- 4-6
3 -- 0-3  5-8
4 -- 0-6  2-6
5 -- 1-5  3-8  6-3  7-2
6 -- 1-1  5-3  7-6
7 -- 5-2  6-6*/
