///in the name of ALLAH
#include<bits/stdc++.h>
#define mx 5*1000001
using namespace std;
typedef long long ll;
uint64_t phi[mx];
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
    phi_1_to_n();
    for(int i=2;i<mx;i++)
    {
        phi[i]=phi[i]*phi[i];
    }
    for(int i=2;i<mx;i++)
    {
        phi[i]=phi[i]+phi[i-1];
    }
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        uint64_t a,b,s=0;
        scanf("%llu%llu",&a,&b);
        s=phi[b]-phi[a-1];
        printf("Case %d: %llu\n",i,s);
    }
}


