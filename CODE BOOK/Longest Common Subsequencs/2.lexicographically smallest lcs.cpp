///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
const int mx =105;
typedef long long ll;
ll dp[mx][mx];
string s1[mx][mx];
ll n,m;
string s,t;
void solve()
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
                s1[i][j]="";
            }
            else if(s[i-1]==t[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                s1[i][j]=s1[i-1][j-1]+s[i-1];
            }
            else
            {
                //dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(dp[i-1][j]>dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                    s1[i][j]=s1[i-1][j];
                }
                else if(dp[i][j-1]>dp[i-1][j])
                {
                    dp[i][j]=dp[i][j-1];
                    s1[i][j]=s1[i][j-1];
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                    s1[i][j]=min(s1[i][j-1],s1[i-1][j]);
                }
            }

        }

    }
    if(dp[n][m]==0)
        cout<<":("<<endl;
    else
        cout<<s1[n][m]<<endl;;
}
int main()
{
    int te;
    cin>>te;
    for(int i=1;i<=te;i++)
    {
        cin>>s>>t;
        n=s.size();
        m=t.size();
        cout<<"Case "<<i<<": ";
        solve();
    }
}



