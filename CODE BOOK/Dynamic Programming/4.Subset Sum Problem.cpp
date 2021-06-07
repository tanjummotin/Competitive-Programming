///BISMILLAHIR RAHMANIR RAHIM
///Tutorial:https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
///Tutorial:https://www.youtube.com/watch?v=_gPcYovP7wc
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isSubsetSum(ll a[],ll n,ll sum)
{
    bool subset[n+1][sum+1];
    for(int i=0; i<=n; i++)
        subset[i][0]=true;
    for(int i=1; i<=sum; i++)
        subset[0][i]=false;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(j>=a[i-1])
                subset[i][j]=subset[i-1][j-a[i-1]]||subset[i-1][j];
            else
                subset[i][j]=subset[i-1][j];
        }
    }
    return subset[n][sum];

}
int main()
{
    ll n,sum;
    cin>>n;
    ll a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cin>>sum;
    bool f=isSubsetSum(a,n,sum);
    if(f==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

/*Subset Sum Problem(Dynamic Programming)
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
Example:

Input:  set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output:  YES  //There is a subset (4, 5) with sum 9.*/
