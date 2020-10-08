///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    scanf("\n");
    for(int te=1; te<=t; te++)
    {
        //scanf("\n");
        string s1,s2;
        getline(cin,s1);
        //scanf("\n");
        getline(cin,s2);
        transform(s1.begin(),s1.end(),s1.begin(), ::tolower);
        transform(s2.begin(),s2.end(),s2.begin(), ::tolower);
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int c1=0,c2=0;
        for(int i=0; i<s1.size(); i++)
        {
            if(s1[i]==' ')
                c1++;
        }
        for(int i=0; i<s2.size(); i++)
        {
            if(s2[i]==' ')
                c2++;
        }
        s1.erase(0,c1);
        s2.erase(0,c2);

        //cout<<s1<<endl<<s2<<endl;
        if(s1==s2)
            cout<<"Case "<<te<<": Yes"<<endl;
        else
            cout<<"Case "<<te<<": No"<<endl;

    }
}
