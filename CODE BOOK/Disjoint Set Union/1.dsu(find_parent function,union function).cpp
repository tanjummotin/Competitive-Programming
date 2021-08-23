/*first e sob node r parent oi node ii
for(int i=1;i<=node;i++)
parent[i]=i
*/
int find_parent(int n)///kono node r parent ber kore/akta point kon set e ber korce
    if(parent[n]==n)
        return n;
    else
        return  parent[n]=find_parent(parent1[n]);
}
void union_(int u,int v)///2 ta set ke merge kore
{
    int par_u=find_parent(u);
    int par_v=find_parent(v);
    parent[par_u]=par_v;
}




