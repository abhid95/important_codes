#include <bits/stdc++.h>
#define MAX 1000000007
#define pb push_back
#define mp make_pair
#define FOR(n) for(i=0;i<n;i++)
#define rep(i,n) for(i=0;i<n;i++)
#define reps(i,a,b) for(i=a;i<=b;i++)
#define swap(a,b) T=a,a=b,b=T
#define que queue<int>
#define s(t) scanf("%d",&t)
#define p(t) printf("%d\n",t)
#define LN 14
#define N 10100
using namespace std;
int T;
vector<int> adj[N],costs[N],indexx[N];
int baseArray[N],ptr,i;
int chainNo,chainInd[N],chainHead[N],posInBase[N];
int depth[N],pa[LN][N],otherEnd[N],subsize[N];
int st[N*6],qt[N*6];
void make_tree(int ss,int se,int index)
{
    if(ss==se-1)
    {
        st[index]=baseArray[ss];
        return;
    }
    make_tree(ss,(ss+se)/2,2*index);
    make_tree((ss+se)/2,se,2*index+1);
    st[index]=max(st[2*index],st[2*index+1]);
}
void update_tree(int ss,int se,int qi,int val,int index)
{
    if(ss>qi || se<=qi) return;
    if(ss==qi && ss==se-1)
    {
        st[index]=val;
        return;
    }
    update_tree(ss,(ss+se)/2,qi,val,2*index);
    update_tree((ss+se)/2,se,qi,val,2*index+1);
    st[index]=max(st[2*index],st[2*index+1]);
}
void query_tree(int ss,int se,int qs,int qe,int index)
{
    if(ss>=qe || se<=qs)
    {
        qt[index]=-1;
        return;
    }
    if(ss>=qs && se<=qe)
    {
        qt[index]=st[index];
        return;
    }
    query_tree(ss,(ss+se)/2,qs,qe,2*index);
    query_tree((ss+se)/2,se,qs,qe,2*index+1);
    qt[index]=max(qt[2*index],qt[2*index+1]);
}
int query_up(int u,int v)
{
    if(u==v)
        return 0;
    int uchain,vchain=chainInd[v],ans=-1;
    while(1)
    {
        uchain=chainInd[u];
        if(uchain==vchain)
        {
            if(u==v) break;
            query_tree(0,ptr,posInBase[v]+1,posInBase[u]+1,1);
            if(qt[1]>ans)
                ans=qt[1];
            break;

        }
        query_tree(0,ptr,posInBase[chainHead[uchain]],posInBase[u]+1,1);
        u=chainHead[uchain];
        u=pa[0][u];

    }
    return ans;
}
int LCA(int u,int v)
{
    if(depth[u]<depth[v]) swap(u,v);
    int diff=depth[u]-depth[v];
    for(i=0;i<LN;i++)
        if((diff>>i)&1)
            u=pa[i][u];
    if(u==v) return u;
    for(i=LN-1;i>=0;i--)
        if(pa[i][u]!=pa[i][v])
        {
            u=pa[i][u];
            v=pa[i][u];
        }
        return pa[0][u];
}
void query(int u,int v)
{
    int lca=LCA(u,v);
    int ans=query_up(u,lca);
    int temp=query_up(v,lca);
    if(temp>ans) ans=temp;
    p(ans);
}
void change(int i,int val)
{
    int u=otherEnd[i];
    update_tree(0,ptr,posInBase[u],val,1);
}
void hld(int curNode,int cost,int prev)
{
    if(chainHead[chainNo]==-1)
        chainHead[chainNo]=curNode;
    chainInd[curNode]=chainNo;
    posInBase[curNode]=ptr;
    baseArray[ptr++]=cost;
    int sc=-1,ncost;
    for(i=0;i<adj[curNode].size();i++)
        if(adj[curNode][i]!=prev)
        {
            if(sc==-1 || subsize[sc]<subsize[adj[curNode][i]])
            {
                sc=adj[curNode][i];
                ncost=costs[curNode][i];
            }
        }
    if(sc!=-1)
        hld(sc,ncost,curNode);
    for(i=0;i<adj[curNode].size();i++)
        if(adj[curNode][i]!=prev)
        {
            if(sc!=adj[curNode][i])
            {
                chainNo++;
                hld(adj[curNode][i],costs[curNode][i],curNode);
            }
        }
}
void dfs(int cur,int prev,int _depth=0)
{
    pa[0][cur]=prev;
    depth[cur]=_depth;
    subsize[cur]=1;
    for(i=0;i<adj[cur].size();i++)
        if(adj[cur][i]!=prev)
        {
            otherEnd[indexx[cur][i]]=adj[cur][i];//same as adj but stores only children nodes
            dfs(adj[cur][i],cur,_depth+1);
            subsize[cur]+=subsize[adj[cur][i]];//call it postorderly itself i.e.,bottom up
        }
}
int main()
{
int j,k,l,n,m,t,T,f,p,ans,cnt,par,u,v,c,a,b;
char x,str[100];
s(t);
while(t--)
{
    s(n);
    FOR(n)
    {
        adj[i].clear();
        costs[i].clear();
        indexx[i].clear();
        chainHead[i]=-1;
        for(j=0;j<LN;j++) pa[j][i]=-1;
    }
    FOR(n-1)
    {
        scanf("%d%d%d",&u,&v,&c);
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
        costs[u].pb(c);
        costs[v].pb(c);
        indexx[u].pb(i);//edge index like we can access them as 1st neighbour of u,2nd so on
        indexx[v].pb(i);
    }
    chainNo=0;
    //printf("hi\n");
    dfs(0,-1);
    //printf("hi\n");
    hld(0,-1,-1);
    //printf("hi\n");
    make_tree(0,ptr,1);
    for(i=1;i<LN;i++)
        for(j=0;j<n;j++)
            if(pa[i-1][j]!=-1)
                pa[i][j]=pa[i-1][pa[i-1][j]];
  //  for(i=0;i<LN;i++){
    //    for(j=0;j<n;j++)
     //       printf("%d ",pa[i][j]);
     //   printf("\n");
   // }
    while(1)
    {
        scanf("%s",str);
        if(str[0]=='D')
            break;
        s(a);s(b);
        if(str[0]=='Q')
            query(a-1,b-1);
        else
            change(a-1,b);

    }
    //FOR(n)
       // p(otherEnd[i]);

}

return 0;
}


