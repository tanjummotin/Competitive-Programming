///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    if(a==b)
        cout<<0<<endl;
    else
    {
        if(a.size()>=b.size())
            cout<<a.size()<<endl;
        else
        {
             cout<<b.size()<<endl;
        }
    }
}
