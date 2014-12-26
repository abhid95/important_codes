// this idea should be applied to all subsequence problem involving negative numbers
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
#define s(t) scanf("%d",&t)
#define p(t) printf("%d\n",t)
using namespace std;


int main()
{
int i,j,l,n,t,T,f,p,ans,cnt,par,ele,a,sum;
char x;
s(t);
while(t--)
{
    map<int,int> m;
    s(n);
    j=0;
    sum=0;
    cnt=0;
    m[0]++;
    FOR(n)
    {
        s(a);
        sum+=a;
        cnt+=m[sum-47];
        m[sum]++;
    }
     p(cnt);
}

return 0;
}



