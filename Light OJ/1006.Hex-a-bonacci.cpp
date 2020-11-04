///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, d, e, f;
ll fn( int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    return( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) );
}
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    for(int te=1;te<=cases;te++){
        scanf("%lli %lli %lli %lli %lli %lli %lli", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %lli\n", te, fn(n) % 10000007);
    }
    return 0;
}
