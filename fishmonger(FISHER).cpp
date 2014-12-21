#include <bits/stdc++.h>
#define MAX 1000000007
#define pb push_back
#define mp make_pair
#define FOR(n) for(i=1;i<=n;i++)
#define rep(i,n) for(i=1;i<=n;i++)
#define reps(i,a,b) for(i=a;i<=b;i++)
#define swap(a,b) T=a,a=b,b=T
#define ll long long int
#define que queue<int>
#define s(t) scanf("%d",&t)
#define p(t) printf("%d\n",t)
using namespace std;
bool mark[100005];
int t,ans1,ans2,n,a[500][500],b[500][500];
void func(int node,int time,int money)
{
    if(money>ans1)
        return;
    if(time>t)
        return;
    if(node==n)
    {
        if(ans1>money)
        {
            ans1=money;
            ans2=time;
        }
        else if(ans1==money)
        {
            if(ans2>time)
            {
                ans2=time;
                ans1=money;
            }
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=node)
        {
            if(mark[i]==false)
            {
                mark[i]=true;
                func(i,time+a[node][i],money+b[node][i]);
                mark[i]=false;
            }
        }
    }
}
int main()
{
int i,j,l,T,f,p,ans,cnt,par,ele;
char x;
while(1)
{
    scanf("%d%d",&n,&t);
    if(n==0)
        break;
    for(i=0;i<=n;i++)
        mark[i]=false;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&b[i][j]);


    mark[1]=true;
    ans1=10000000;
    ans2=10000000;
    func(1,0,0);
    printf("%d %d\n",ans1,ans2);

}


return 0;
}



