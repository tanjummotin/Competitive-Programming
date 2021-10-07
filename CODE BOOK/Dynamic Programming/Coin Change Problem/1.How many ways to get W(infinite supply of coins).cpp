///BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
using namespace std;
int coinchange(int a[],int w,int n)
{
    int table[n][w+1];
    memset(table,0,sizeof(table));
    for(int i=0; i<n; i++)
    {
        table[i][0]=1;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(i==0)
            {
                if(a[i]>j)
                    table[i][j]=0;
                    else
                         table[i][j]=table[i][j-a[i]];
            }
            else
            {
                if(a[i]>j)
                    table[i][j]=table[i-1][j];
                else
                    table[i][j]=table[i-1][j]+table[i][j-a[i]];
            }
        }
    }
    return table[n-1][w];
}
int main()
{
    int n,m,w;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cin>>w;
    int r=coinchange(a,w,n);
    cout<<r<<endl;

}

