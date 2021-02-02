///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> z_array(string s)
{
    int n=s.size();
    vector<int>z(n,0);
    int l=0,r=0;
    for(int i=1;i<n;i++)
    {
        if(i<=r)
        {
            z[i]=min(r-i+1,z[i-l]);
        }
        while(i+z[i]<n && s[z[i]]==s[i+z[i]])
        {
            z[i]++;
        }
        if(i+z[i]-1>r)
        {
            l=i;
            r=i+z[i]-1;
        }
    }
    return z;
}
int main()
{
    string s;
    cin>>s;
    vector<int>z=z_array(s);
    int n=s.size();
    for(int i=0;i<n;i++)
        cout<<z[i]<<" ";
    cout<<endl;
    vector<int> occ(n+1);
    for(int i=0;i<n;i++)
    {
        occ[z[i]]++;
    }
    for(int i=n-1;i>0;i--)
    {
        occ[i-1]+=occ[i];
    }
    for(int i=0;i<=n;i++)
        occ[i]++;
    for(int i=1;i<=n;i++)
        cout<<occ[i]<<" ";
    cout<<endl;

}
/*
aabaaab
5 3 2 1 1 1 1
*/
