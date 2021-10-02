/*first e sob node r parent oi node ii
for(int i=1;i<=node;i++){
parent[i]=i;
siz[i]=1;
}
*/
///find_parent->kono node r parent ber kore/akta point kon set e ber korce
///union_ --> 2 ta set ke merge kore
///siz[i]--->size of component with parent i
int find_parent(int n)
{
    if(parent[n]==n)
        return n;
    else
        return  parent[n]=find_parent(parent[n]);
}
void union_(int u,int v)
{
    int par_u=find_parent(u);
    int par_v=find_parent(v);
    if(par_u==par_v)
        return;
    if(siz[par_u]>=siz[par_v])
    {
        siz[par_u]+=siz[par_v];
        parent[par_v]=par_u;
    }
    else
    {
        siz[par_v]+=siz[par_u];
        parent[par_u]=par_v;
    }
}


