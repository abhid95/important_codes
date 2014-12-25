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
ll i,j,l,n,m,t,T,f,p,ans,cnt,par,ele,max,sum,a[100005],mn,rct;
char x;
s(t);
while(t--)
{
    s(n);
    FOR(n)
        s(a[i]);
    max=-MAX;
    mn=rct=sum=0;
    cnt=1;
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
        if(sum-mn>max)
        {
            max=sum-mn;
            rct=cnt;
        }
        else if(sum-mn==max)
            rct+=cnt;
        if(sum<mn)
        {
            mn=sum;
            cnt=1;
        }
        else if(sum==mn)
            cnt++;
    }

    printf("%lld %lld\n",max,rct);
}

return 0;
}



