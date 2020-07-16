///in the name of ALLAH
///Euler phi pre-computation from 1 to n (nlog(log(n)))
///Tutorial:
#include<bits/stdc++.h>
#define mx 1000005
using namespace std;
typedef long long ll;
ll phi[mx];
void phi_1_to_n( )
{
    for(int i=0;i<mx;i++)phi[i]=i;
    for(int i=2;i<mx;i++)
    {
        if(phi[i]==i)///a prime
        {
            for(int j=i;j<mx;j+=i)
            {
                phi[j]-=phi[j]/i;
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    phi_1_to_n();
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<phi[n]<<endl;
    }
}

