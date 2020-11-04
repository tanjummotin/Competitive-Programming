///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, d, e, f,n;
int main() {
    int   cases;
    scanf("%d", &cases);
    for(int te=1;te<=cases;te++){
        scanf("%lli %lli %lli %lli %lli %lli %lli", &a, &b, &c, &d, &e, &f, &n);
        ll dp[10005];
        if(n==0)dp[0]=a;
        else if(n==1)dp[1]=b;
        else if(n==2)dp[2]=c;
        else if(n==3)dp[3]=d;
        else if(n==4)dp[4]=e;
        else if(n==5)dp[5]=f;
        else
        {
            dp[0]=a;dp[1]=b;dp[2]=c;dp[3]=d;dp[4]=e;dp[5]=f;
            for(int i=6;i<=n;i++)
            {
                dp[i]=(dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6])%10000007;
                //cout<<dp[i]<<" ";
            }//cout<<endl;
        }
        printf("Case %d: %lli\n", te,dp[n]  % 10000007);
    }
    return 0;
}
