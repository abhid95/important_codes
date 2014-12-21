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
ll i,j,l,n,m,t,T,f,p,ans,cnt,par,ele,prod,a[100005];
char x;
s(t);
while(t--)
{
    s(n);
    FOR(n)
        s(a[i]);
    sort(a,a+n);
    prod=1;
    FOR(n)
        prod=prod*(a[i]-i)%MAX;//trick lies here
    if(prod<=0)
         prod=0;
    p(prod);
}
printf("KILL BATMAN\n");


return 0;
}



