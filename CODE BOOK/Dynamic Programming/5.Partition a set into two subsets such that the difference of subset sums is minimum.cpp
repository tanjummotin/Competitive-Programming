///BISMILLAHIR RAHMANIR RAHIM
///Tutorial:https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
///Tutorial:https://www.youtube.com/watch?v=-GtpxG6l_Mc
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll findMin(ll a[],ll n)
{
    ll sum=0;
    for(int i=0; i<n; i++)
        sum+=a[i];
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

    ll diff=INT_MAX;

    for(int j=sum/2; j>=0; j--)
    {
        if(subset[n][j]==true)
        {
            diff=sum-2*j;
            break;
        }
    }
    return diff;

}
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    cout<<findMin(a,n)<<endl;;

}
/*
Sum of subset differences
Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example:
Input:  arr[] = {1, 6, 11, 5}
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11}, sum of Subset2 = 11
*/

