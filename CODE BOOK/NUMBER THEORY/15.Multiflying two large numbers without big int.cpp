///in the name of ALLAH
#include<bits/stdc++.h>
#define mx 600
using namespace std;
typedef long long ll;
int main()
{
    string s1,s2;
    while(cin>>s1)///verify the whole process by multiplying two numbers by hand
    {
        cin>>s2;
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        ll a[mx];
        for(int i=0;i<mx;i++)
            a[i]=0;
        for(int i=0;i<s2.size();i++)
        {
            for(int j=0;j<s1.size();j++)
            {
                a[i+j]+=(s1[j]-'0')*(s2[i]-'0');
            }
        }

        for(int i=0;i<mx;i++)
        {
            a[i+1]=a[i+1]+(a[i]/10);
            a[i]=a[i]%10;
        }
        int i;
        for( i=mx-1;i>0;i--)
        {
            if(a[i]!=0)
                break;
        }

        for(int j=i;j>=0;j--)
            cout<<a[j];
        cout<<endl;


    }
}


