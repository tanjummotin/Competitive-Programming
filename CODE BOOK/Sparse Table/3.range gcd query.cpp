///BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

const int maxn=100000;
const int maxlog=25;
ll n;
ll logs[maxn];/// logs[i] means such maximum p that 2^p <= i
ll ST[maxlog][maxn];///table[i][j] means j teke suru 2^i length r sub array r modde minimum
ll a[maxn];

void computeLogs()
{
    logs[1]=0;
    for(int i=2; i<=n; i++)
        logs[i]=logs[i/2]+1;
}

void buildST()
{
    for(int i=0; i<=logs[n]; i++)
    {
        int curlen=1<<i;
        for(int j=0; j+curlen<=n; j++)
        {
            if(curlen==1)
                ST[i][j]=a[j];
            else
                ST[i][j]=__gcd(ST[i-1][j],ST[i-1][j+curlen/2]);
        }
    }
}
ll range_gcd(int l,int r)
{
    int p=logs[r-l+1];
    int plen=1 << p;
    ll ans= __gcd(ST[p][l],ST[p][r-plen+1]);
    return ans;
}
int main()
{
    ll l,r,q;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    computeLogs();
    buildST();

    cin>>q;
    for(int i=1; i<=q; i++)
    {
        cin>>l>>r;///0 indexed
        cout<<range_gcd(l,r)<<endl;
    }
}



