
///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    for(int te=1; te<=t; te++)
    {
        scanf("\n");
        string s1,s2;
        getline(cin,s1);
        scanf("\n");
        getline(cin,s2);
        transform(s1.begin(),s1.end(),s1.begin(), ::tolower);
        transform(s2.begin(),s2.end(),s2.begin(), ::tolower);
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int l=lower_bound(s1.begin(),s1.end(),' ')-s1.begin();
        int u=upper_bound(s1.begin(),s1.end(),' ')-s1.begin();
        //cout<<l<<" "<<u<<endl;
        s1.erase(l,u-l);
        int l1=lower_bound(s2.begin(),s2.end(),' ')-s2.begin();
        int u1=upper_bound(s2.begin(),s2.end(),' ')-s2.begin();
        //cout<<l<<" "<<u<<endl;
        s2.erase(l1,u1-l1);

        //cout<<s1<<endl<<s2<<endl;
        if(s1==s2)
            cout<<"Case "<<te<<": Yes"<<endl;
        else
            cout<<"Case "<<te<<": No"<<endl;

    }
}
