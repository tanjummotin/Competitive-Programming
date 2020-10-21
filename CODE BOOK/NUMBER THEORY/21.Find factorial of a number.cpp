///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef uint64_t ll;
ll dp[1000000];
ll factorial(ll n)
{
    if(dp[n]!=0)
        return dp[n];
   if(n==1)
        return 1;

   dp[n]=factorial(n-1)*n;
   return dp[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;

}

