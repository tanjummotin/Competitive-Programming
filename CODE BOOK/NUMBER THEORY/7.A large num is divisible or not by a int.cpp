///in the name of ALLAH
///Tutorial:http://nayeemmollickjoy.blogspot.com/2017/07/httpwww.html
/// find a large number is divisible or not by a int
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        string a;
        ll b,r=0,p;
        cin>>a>>b;
        if(a[0]=='-')///if the number is negative,remove the negative sign
            a.erase(0,1);
        for(int i=0;i<a.size();i++)///see the division process by hand
        {
            p=r*10+(a[i]-'0');
            r=p%b;
        }
       printf("Case %d: ",i);
        if(r==0)
            cout<<"divisible"<<endl;
        else
            cout<<"not divisible"<<endl;

    }
}

