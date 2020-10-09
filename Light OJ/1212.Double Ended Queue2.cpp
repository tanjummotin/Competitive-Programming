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
        int n,m,q=0;
        deque<int>d;
        cin>>n>>m;
        cout<<"Case "<<te<<":"<<endl;
        for(int i=1; i<=m; i++)
        {
            string s;
            int x;
            cin>>s;
            if(s=="pushLeft")
            {
                cin>>x;
                if(q==n)
                    cout<<"The queue is full"<<endl;
                else
                {
                    q++;
                    d.push_front(x);
                    cout<<"Pushed in left: "<<x<<endl;
                }

            }
            else if(s=="pushRight")
            {
                cin>>x;
                if(q==n)
                    cout<<"The queue is full"<<endl;
                else
                {
                    q++;
                    d.push_back(x);
                    cout<<"Pushed in right: "<<x<<endl;
                }


            }
            else if(s=="popLeft")
            {
                if(q==0)
                    cout<<"The queue is empty"<<endl;
                else
                {
                    q--;

                    cout<<"Popped from left: "<<d.front()<<endl;
                    d.pop_front();
                }
            }
            else if(s=="popRight")
            {
                if(q==0)
                    cout<<"The queue is empty"<<endl;
                else
                {
                    q--;
                    cout<<"Popped from right: "<<d.back()<<endl;
                    d.pop_back();
                }
            }
        }
    }
}
