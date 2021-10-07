///BISMILLAHIR RAHMANIR RAHIM
/// find the number of ways in which H can choose a subset of sum S1 and B can choose a subset of sum S2
///such that s1+s2=W and |s1-s2|<=K
///https://codeforces.com/gym/101102/problem/A
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
ll table1[155][15001],table2[155][15001],n,m,K1,w;
ll a[155],b[155];
const ll mod=1e9+7;
void coinchange()
{
    memset(table1,0,sizeof(table1));
    memset(table2,0,sizeof(table2));
    for(int k=0; k<n; k++)
    {
        table1[k][0]=1;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=w; j>=1; j--)
        {
            if(i==0)
            {
                if(a[i]>j)
                {
                    table1[i][j]=0;
                }
                else
                {
                    table1[i][j]=table1[i][j-a[i]]%mod;
                }
            }
            else
            {
                if(a[i]>j)
                    table1[i][j]=table1[i-1][j];
                else
                    table1[i][j]=(table1[i-1][j]+table1[i-1][j-a[i]])%mod;
            }
        }
    }
    for(int k=0; k<m; k++)
    {
        table2[k][0]=1;
    }
    for(int i=0; i<m; i++)
    {
        for(int j=w; j>=1; j--)
        {
            if(i==0)
            {
                if(b[i]>j)
                    table2[i][j]=0;
                else
                    table2[i][j]=table2[i][j-b[i]]%mod;
            }
            else
            {
                if(b[i]>j)
                    table2[i][j]=table2[i-1][j]%mod;
                else
                    table2[i][j]=(table2[i-1][j]+table2[i-1][j-b[i]])%mod;
            }
        }
    }
    ll ans=0;
    for(int s1=0; s1<=w; s1++)
    {
        int s2=w-s1;
        if(abs(s1-s2)<=K1)
        {
            ans=(ans%mod+(table1[n-1][s1]*table2[m-1][s2])%mod)%mod;
        }
    }
    cout<<ans%mod<<endl;
}
int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>K1>>w;
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int j=0; j<m; j++)
            cin>>b[j];
        coinchange();
    }
}

/*
2
4 3 5 18
2 3 4 1
10 5 5
2 1 20 20
10 30
50
output-
2
0
*/

