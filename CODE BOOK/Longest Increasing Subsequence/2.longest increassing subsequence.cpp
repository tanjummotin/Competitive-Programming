///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx=1e3+5;
int n;
int a[mx];
int dp[mx];

///recursive version
int solve(int i)
{
    if(i==0)
        return 1;
        int& ans=dp[i];
        if(ans!=-1)return ans;
        ans=1;
        for(int j=0;j<i;j++)///i tomo ta nicci
        {
            if(a[j]<=a[i])
                ans=max(ans,1+solve(j));
        }
        ans=max(ans,solve(i-1));///i tomo ta na niye
        return ans;

}
///Iterative version
int solve()
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[j]<=a[i])
                dp[i]=max(dp[i],1+dp[j]);
        }
        ans=max(ans,dp[i]);
    }
    return ans;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
        ///Iterative
        cout<<solve()<<endl;
        ///Recursive
        memset(dp,-1,sizeof(dp));
        cout<<solve(n-1)<<endl;
}

