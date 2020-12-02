///in the name of ALLAH
///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
struct node
{
    node* child[26];
    bool end_mark;
    node()
    {
        for(int i=0; i<26; i++)
        {
            child[i]=NULL;
        }
        end_mark=false;
    }
};
node* root;
///AEH
void Insert(string s)
{
    node *cur=root;
    for(auto ch:s)
    {
        int letter=ch-'A';
        if(cur->child[letter]==NULL)
        {
            cur->child[letter]=new node();
        }
        cur=cur->child[letter];
    }
    cur->end_mark=true;
}
///AC
bool Search(string s)///kono string trie e ache naki nai
{
    node *cur=root;
    for(auto ch:s)
    {
        int letter=ch-'A';
        if(cur->child[letter]==NULL)
        {
            return false;
        }
        else
            cur=cur->child[letter];
    }
    if(cur->end_mark==true)
        return true;
    else
        return false;
}

void Delete_all(node *cur)///root pathaile pora tree delete hobe
{
    ///je node pathabo tar subtree delete hobe,
    for(int i=0; i<26; i++)
    {
        if(cur->child[i])
        {
            Delete_all(cur->child[i]);
        }
    }
    delete(cur);
}
bool kono_child_ase_kina(node *cur)
{
    for(int i=0; i<26; i++)
    {
        if(cur->child[i])
            return true;
    }
    return false;
}
///abc lvl=0,A lvl=1,B lv2,C
node* Delete(node* cur,string s,int lvl)///trie teke kono string delete korbo
{
    if(cur==NULL)
        return NULL;
    if(lvl==s.size())///Base case
    {
        if(cur->end_mark)
        {
            cur->end_mark=false;
        }
        if(kono_child_ase_kina(cur)==false)
        {
            delete(cur);
            cur==NULL;
        }
        return NULL;
    }
    int letter=s[lvl]-'A';
    cur->child[letter]=Delete(cur->child[letter],s,lvl+1);
    if(kono_child_ase_kina(cur)==false && cur->end_mark==false)
    {
        delete(cur);
        cur=NULL;
    }
}
int main()
{
    root=new node();
    ///Inserting
    int t;
    cin>>t;
    string s;
    while(t--)
    {
        getchar();
        cin>>s;
        Insert(s);
    }
    ///Searching
    int p;
    cin>>p;
    while(p--)
    {
        cin>>s;
        if(Search(s)==true)
            cout<<s<<" trie te ase"<<endl;
        else
            cout<<s<<" trie te nai"<<endl;
    }
    ///Delete
    int q;
    cin>>q;
    while(q--)
    {
        cin>>s;
        Delete(root,s,0);
    }
    ///Check kore dekhi delete hoice kina
    int p1;
    cin>>p1;
    while(p1--)
    {
        cin>>s;
        if(Search(s)==true)
            cout<<s<<" trie te ase"<<endl;
        else
            cout<<s<<" trie te nai"<<endl;
    }
}


