//in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int a[n],ans1,ans2;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int i,j;
    i=0;j=n-1;
    bool f=0;
    while(i<j)
    {
        if(a[i]+a[j]==x)
        {
            ans1=a[i];
            ans2=a[j];
            f=1;
            break;
        }
        else if(a[i]+a[j]<x)
        i++;
        else
            j--;

    }
    if(f==1)
        cout<<ans1<<" "<<ans2<<endl;
}

///Testcase
/*9 48
30 29 26 22 15 14 11 9 8

output::22 26  */
