///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    for(int te=1;te<=t;te++)
    {
        int n;
        cin>>n;
        map<int,string>mp;
        set<ll>se;
        set<ll>:: iterator it;
        for(int i=1;i<=n;i++)
        {
            string s;
            int l,w,h;
            cin>>s;

            cin>>l>>w>>h;
            mp[l*w*h]=s;
            se.insert(l*w*h);
        }
        cout<<"Case "<<te<<": ";
        if(se.size()==1)
            cout<<"no thief"<<endl;
            else if(se.size()==2)
            {
                 int c=0;
                string x,y;
                for(it=se.begin();it!=se.end();it++)
                {
                    c++;
                    if(c==1)
                        x=mp[*it];
                        if(c==2)
                            y=mp[*it];

                }
                cout<<y<<" took chocolate from "<<x<<endl;
            }
            else
            {
                int c=0;
                string x,y;
                for(it=se.begin();it!=se.end();it++)
                {
                    c++;
                    if(c==1)
                        x=mp[*it];
                        if(c==3)
                            y=mp[*it];

                }
                cout<<y<<" took chocolate from "<<x<<endl;
            }
    }
}
