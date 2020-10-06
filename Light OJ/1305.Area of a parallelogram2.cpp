///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
int main()
{
    int t;
    cin>>t;
    for(int te=1;te<=t;te++)
    {
        ll ax,bx,cx,dx,ay,by,cy,dy;

        cin>>ax>>ay>>bx>>by>>cx>>cy;
        dx=ax+cx-bx;
        dy=ay+cy-by;
        ll area=0.5*(ax*by+bx*cy+cx*dy+dx*ay-bx*ay-cx*by-dx*cy-ax*dy);
        cout<<"Case "<<te<<": "<<dx<<" "<<dy<<" "<<abs(area)<<endl;


    }
}

