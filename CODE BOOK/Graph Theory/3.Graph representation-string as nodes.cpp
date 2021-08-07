///in the name of ALLAH
///Graph representation using adjacency list ---string as node
///Tutorial:
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<string>nodeNames;
map<string,int>nodeNumbers;
int main()
{
    ll node,edge;
    cin>>node>>edge;
    vector< pair<ll,ll> >v[node];

    for(int i=0;i<node;i++)
    {
        string str;
        cin>>str;
        nodeNames.push_back(str);
        nodeNumbers[str]=i;
    }
    for(int i=0;i<edge;i++)
    {
        string str1,str2;
        cin>>str1>>str2;
        ll source;
        pair<ll,ll>p;
        source=nodeNumbers[str1];
        p.first=nodeNumbers[str2];
        cin>>p.second;
        v[source].push_back(p);
        ll source2=p.first;
        p.first=source;
        v[source2].push_back(p);
    }
    for(int i=0;i<node;i++)
    {
        cout<<nodeNames[i]<<"--";
        for(int j=0;j<v[i].size();j++)
        {
          cout<<nodeNames[v[i][j].first]<<"-"<<v[i][j].second<<" ";
        }
        cout<<endl;
    }
}
/*
8 9
Rayerbag
Niketon
Mirpur
Dhanmondi
Jatrabari
Rampura
Badda
Gulshan
Rayerbag Dhanmondi 3
Rayerbag Jatrabari 6
Niketon Rampura 5
Niketon Badda 1
Mirpur Jatrabari 6
Dhanmondi Rampura 8
Rampura Badda 3
Rampura Gulshan 2
Badda Gulshan 6*/
