///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    node* child[26];
    int end_mark;
    node()
    {
        for(int i=0; i<26; i++)
        {
            child[i]=NULL;
        }
        end_mark=0;
    }
};
node* root;
void Insert(string s)
{
    node *cur=root;
    for(auto ch:s)
    {
        int letter=ch-'a';
        if(cur->child[letter]==NULL)
        {
            cur->child[letter]=new node();
        }
        cur=cur->child[letter];
        cur->end_mark=(cur->end_mark)+1;
    }

}
int check(string st)
{
    node *cur=root;
    for(int i=0; i<st.size(); i++)
    {
        int letter=st[i]-'a';
        if(cur->child[letter]==NULL)
        {
            return 0;
        }
        else
        cur=cur->child[letter];
        //cout<<cur->end_mark<<endl;
    }
    return cur->end_mark;
}
int main()
{

    root=new node();
    int n;
    cin>>n;
    string s[n],s1;
    for(int i=0; i<n; i++)
    {
        getchar();
        cin>>s[i];
        Insert(s[i]);
    }
        getchar();
        cin>>s1;
        cout<<check(s1)<<endl;

}

/*
input:
12
bulldog
dog
dogged
doggedly
doggerel
dogma
dogmatic
dogmatism
dogs
catastroph
catastroph
doctor
dog

output: 8
*/




