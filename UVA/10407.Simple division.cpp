///in the name of ALLAH
///.Find the largest number d such that when the element of the array are divided
///by d leaves the same remainder
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll ar[1005];
    while(1)
    {
        cin>>ar[0];
        if(ar[0]==0)
            break;
        else
        {
            ll index=1,diff,g=0;///as gcd(0,x)=x;
            while(1)
            {
                cin>>ar[index];
                if(ar[index]==0)
                    break;
                else
                    index++;
            }

            for(int i=1; i<index; i++)
            {
                diff=ar[i]-ar[i-1];
                g=__gcd(g,diff);
            }
            ///if gcd is negative
            if(g<0)g=-1*g;
            cout<<g<<endl;
        }
    }

}

