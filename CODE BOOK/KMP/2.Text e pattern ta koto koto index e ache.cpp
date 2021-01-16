///in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>createTempArray(string pattern)
{
    vector<ll>lps(pattern.size());
    int index=0;
    for(int i=1;i<pattern.size();)
    {
        if(pattern[index]==pattern[i])
        {
            lps[i]=index+1;
            index++;i++;
        }
        else
        {
            if(index!=0)
                index=lps[index-1];
            else
            {
                lps[i]=0;i++;
            }
        }
    }
    return lps;
}
void kmp(string text,string pattern)
{
    vector<ll>lps=createTempArray(pattern);
    int i=0,j=0;
    bool f=0;
    while(i<text.size())
    {
        if(text[i]==pattern[j])
        {
            i++;j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
                else i++;
        }
        if(j==pattern.size())
        {
           cout<<i-j<<" ";
           j=lps[j-1];
        }

    }


}
int main()
{
    string pattern,text;
    getline(cin,text);
    getline(cin,pattern);
    kmp(text,pattern);
}

