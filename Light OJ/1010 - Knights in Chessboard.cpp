///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t,x;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int m,n;
        cin>>m>>n;
        if(n<m)
            swap(m,n);
        if(m==1 )x=n;
        else if(m==2)
        {
           x=(n/4);
           x=x*4;
           if(n%4!=0)
           {
               if(n%4==3)x+=4;
               else if(n%4==2)x+=4;
               else
                x+=2;

           }

        }
        else if(m==3)
        {
            x=n/2;
            x=3*x;
            if(n%2!=0)x+=2;
        }
       else
       {
           x=(m*n)/2;
           if((m*n)%2!=0)x++;
       }
        cout<<"Case "<<i<<": "<<x<<endl;
    }
}
