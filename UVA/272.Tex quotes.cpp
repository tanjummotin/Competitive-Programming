///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   string s;
   ll c=0;
   while(getline(cin,s))
   {
     for(int i=0;i<s.size();i++)
     {
         if(s[i]=='"')
         {
             c++;
             if(c%2!=0)
             {
                 s.replace(i,1,"``");
             }
             else
                s.replace(i,1,"''");
         }
     }
     cout<<s<<endl;

   }


}
