///in the name of ALLAH
///idone e run koro,taholei hobe
#include<bits/stdc++.h>
#define mx 1000005
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
vector<u64>prime;
void sieve()
{
    bool flag[mx];
    memset(flag,0,sizeof(flag));
    flag[1]=1;
    for(int i=4; i<=mx; i+=2)
    {
        flag[i]=1;
    }
    for(int i=3; i<=sqrt(mx); i+=2)
    {
        if(flag[i]==0)
        {
            for(int j=2*i; j<=mx; j+=i)
                flag[j]=1;
        }
    }
    for(int i=2; i<mx; i++)
    {
        if(flag[i]==0)
        {
            prime.push_back(i);
        }
    }
    //for(int i=0;i<10;++i)
    //cout<<prime[i]<<endl;
}

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}
int main()
{
    sieve();
    int t;
    cin>>t;
    u64 n,c;
    for(int i=0; i<t; i++)
    {
        cin>>n;
        u64 ans=1;
        for(int i=0; i<prime.size()&& prime[i]*prime[i]*prime[i]<=n; i++)
        {
            if(n%prime[i]==0)
            {
                c=0;
                while(n%prime[i]==0)
                {
                    n/=prime[i];
                    c++;
                }
                ans*=(c+1);
                //cout<<"in "<<prime[i]<<" "<<c<<" "<<ans<<endl;
            }
        }
        //cout<<ans<<" "<<n<<endl;
        u64 x=sqrt(n);
        if(MillerRabin(n))
            ans*=2;
        else if((x*x==n) && MillerRabin(x))
            ans*=3;
        else if(n!=1)
            ans*=4;
        cout<<ans<<endl;

    }

}
