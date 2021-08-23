///BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int parent[100005];
 vector<int>vec[100005];
const long long mod=1000000007;
int find_parent(int n){///kono node r parent ber kore/akta point kon set e ber korce
    if(parent[n]==n)
        return n;
    else
        return  parent[n]=find_parent(parent[n]);
}
int main()
{
    int node,edge,u,v,x,y;
     cin>>node>>edge;
    for(int i=1;i<=node;i++)
        parent[i]=i;
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v;
        x=find_parent(u);
        y=find_parent(v);
        parent[x]=y;
    }
    for(int i=1;i<=node;i++)
    {
        x=find_parent(i);
        vec[x].push_back(i);
    }
    ll ans=1,c=0;
    for(int i=1;i<=node;i++)
    {
        if(vec[i].size()!=0)
         {
             c++;
         }
    }
    cout<<"Number of connected component = "<<c<<endl;
    cout<<"Sizes of the connected components = ";
    for(int i=1;i<=node;i++)
    {
        if(vec[i].size()!=0)
         {
            cout<<vec[i].size()<<" ";
         }
    }
    cout<<endl;
}
