///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    node* child[10];
    bool end_mark;
    node()
    {
        for(int i=0; i<10; i++)
        {
            child[i]=NULL;
        }
        end_mark=false;
    }
};
node* root;
void Insert(string s)
{
    node *cur=root;
    for(auto ch:s)
    {
        int letter=ch-'0';
        if(cur->child[letter]==NULL)
        {
            cur->child[letter]=new node();
        }
        cur=cur->child[letter];
    }
    cur->end_mark=true;
}
bool check(string st)
{
    node *cur=root;
    for(int i=0; i<st.size(); i++)
    {
        int letter=st[i]-'0';

        if(i!=st.size() && cur->end_mark==true)
                return false;
            cur=cur->child[letter];
        }
    return true;
}
void Delete_all(node *cur)///root pathaile pora tree delete hobe
 {                        ///je node pathabo tar subtree delete hobe,
     for(int i=0;i<10;i++)
     {
         if(cur->child[i])
         {
             Delete_all(cur->child[i]);
         }
     }
     delete(cur);
 }
int main()
{
    int t;
    scanf("%d",&t);
    for(int te=1; te<=t; te++)
    {
        root=new node();
        int n;
        scanf("%d",&n);
        string s[n];
        for(int i=0; i<n; i++)
        {
            getchar();
            cin>>s[i];
            Insert(s[i]);
        }
        bool f=1;
        for(int i=0; i<n; i++)
        {
            if(check(s[i])==false)
            {
                f=0;
                break;
            }
        }
        printf("Case %d: ",te);
        if(f==1)
            printf("YES\n");
        else
            printf("NO\n");
           Delete_all(root);

    }
}
