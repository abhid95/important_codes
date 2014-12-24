#include <bits/stdc++.h>
#define MAX 1000000007
#define pb push_back
#define mp make_pair
#define FOR(n) for(i=0;i<n;i++)
#define rep(i,n) for(i=0;i<n;i++)
#define reps(i,a,b) for(i=a;i<=b;i++)
#define swap(a,b) T=a,a=b,b=T
#define ll long long int
#define que queue<int>
#define s(t) scanf("%lld",&t)
#define p(t) printf("%lld\n",t)
using namespace std;


int main()
{
ll i,j,l,n,m,t,T,f,p,ans,cnt,par,ele,td,tmp,s,d,tc=1,a[100005],ts;
char x;
s(t);
while(t--)
{
    s(n);
    n--;
    for(i=0;i<n;i++) s(a[i]);
    ts=0;tmp=0;ans=-1;s=-1;d=-1;td=0;
    for(i=0;i<n;i++)
    {
        td=i;
        if(tmp+a[i]>ans)
        {
            ans=tmp+a[i];
            s=ts;
            d=td;
        }
        else if(tmp+a[i]==ans && td-ts>d-s)
        {
            s=ts;
            d=td;
        }
        if(tmp+a[i]>=0) tmp+=a[i];
        else if(tmp+a[i]<0)
        {
            tmp=0;
            ts=i+1;
        }
    }
    if(s!=-1) printf("The nicest part of route %lld is between stops %lld and %lld\n", tc++, s+1, d+2);
    else printf("Route %lld has no nice parts\n",tc++);
}

return 0;
}



