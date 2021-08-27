///BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const ll mx=1e5;
const int block=700;
struct query
{
    int l,r,id;

};
int a[100005],ans[100005],freq[100005];
int unique_values,L,R;
query queries[100005];

bool cmp(query a,query b)
{
    int block_a=a.l/block;
    int block_b=b.l/block;
    if(block_a==block_b)
        return a.r<b.r;
        else
          return block_a<block_b;
}
void add(int idx)
{
    freq[a[idx]]++;
    if(freq[a[idx]]==1)unique_values++;
}
void remov(int idx)
{
    freq[a[idx]]--;
    if(freq[a[idx]]==0)unique_values--;
}

int main()
{
    int t,n,Q;
    scanf("%d",&t);
    for(int te=1;te<=t;te++)
    {
        scanf("%d%d",&n,&Q);
        L=0,R=-1;
        unique_values=0;
        memset(freq,0,sizeof freq);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<Q; i++)
        {
            scanf("%d%d",& queries[i].l,&queries[i].r);
            --queries[i].l;
            --queries[i].r;
            queries[i].id=i;
        }
        sort(queries,queries+Q,cmp);
        for(int i=0;i<Q;i++)
        {
           while(queries[i].l < L)add(--L);///include hocce
           while(queries[i].l > L)remov(L++);///exclude hocce
           while(queries[i].r < R)remov(R--);///exclude hocce
           while(queries[i].r > R)add(++R);///include hocce
           ans[queries[i].id]=unique_values;
        }
        printf("Case %d:\n",te);
        for(int i=0;i<Q;i++)
            printf("%d\n",ans[i]);
    }
}


