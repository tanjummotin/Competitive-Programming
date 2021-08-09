///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int mx =1e3+9;
typedef long long ll;
ll dp[mx][mx];
ll n,m;
string s,t;
///Iterative
ll solve()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(s[i-1]==t[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }

    return dp[n][m];
}
int main()
{

    cin>>s>>t;
    n=s.size();
    m=t.size();
    ///Iterative version
    cout<<solve()<<endl;
}

