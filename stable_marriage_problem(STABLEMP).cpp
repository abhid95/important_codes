#include <bits/stdc++.h>
#define MAX 1000000007
#define pb push_back
#define mp make_pair
#define FOR(n) for(i=0;i<=n;i++)
#define rep(i,n) for(i=0;i<=n;i++)
#define reps(i,a,b) for(i=a;i<=b;i++)
#define swap(a,b) T=a,a=b,b=T
#define ll long long int
#define que queue<int>
#define s(t) scanf("%lld",&t)
#define p(t) printf("%lld\n",t)
using namespace std;
ll mprefer[1005][1005];
ll wprefer[1005][1005];
ll wPartner[100005];
ll mPartner[100005];
ll n;
bool wprefersM1OverM(ll w,ll m,ll m1)
{
    ll i;
    for(i=1;i<=n;i++)
    {
        if(wprefer[w][i]==m1)
            return true;
        if(wprefer[w][i]==m)
            return false;
    }
}
void stableMarriage()
{
    ll m,i,m1,w;
    bool mFree[100005];
    memset(wPartner,-1,sizeof wPartner);
    memset(mFree,false,sizeof mFree);
    ll freeCount=n;
    while(freeCount>0)
    {
        for(m=1;m<=n;m++)
            if(mFree[m]==false)
                break;
        for(i=1;i<=n && mFree[m]==false;i++)
        {
            w=mprefer[m][i];
            if(wPartner[w]==-1)
            {
                wPartner[w]=m;
                mFree[m]=true;
                freeCount--;
            }
            else
            {
                m1=wPartner[w];
                if(wprefersM1OverM(w,m,m1)==false)
                {
                    wPartner[w]=m;
                    mFree[m]=true;
                    mFree[m1]=false;
                }
            }
        }
    }
}
int main()
{
ll i,j,l,m,t,T,f,p,ans,cnt,par,ele;
char x;
s(t);
while(t--)
{
    s(n);
    for(i=1;i<=n;i++)
        for(j=0;j<=n;j++)
            s(wprefer[i][j]);
    for(i=1;i<=n;i++)
        for(j=0;j<=n;j++)
            s(mprefer[i][j]);
    stableMarriage();
    for(i=1;i<=n;i++)
        mPartner[wPartner[i]]=i;
    for(i=1;i<=n;i++)
        printf("%lld %lld\n",i,mPartner[i]);
}

return 0;
}



