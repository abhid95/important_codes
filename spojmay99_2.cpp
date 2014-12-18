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
ll i,j,k,l,n,m,t,T,f,p,ans,cnt,par,ele;
char x,b[]={'m','a','n','k','u'},a[100005];
s(t);
while(t--)
{
    s(n);
    k=0;
    while(n>0)
    {
        n--;//here is the logic,no need of pow
        a[k++]=b[n%5];
        n/=5;
    }
    a[k]='\0';
    FOR(k/2)
        swap(a[i],a[k-i-1]);
    printf("%s\n",a);
}


return 0;
}



