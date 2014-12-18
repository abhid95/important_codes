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
ll i,j,k,l,n1,n2,m,t,T,f,p,ans,cnt,par,ele;
char x,a[100005];
s(t);
while(t--)
{
    n1=0;
    n2=0;
    scanf("%s",a);
    l=strlen(a);
    FOR(l)
    {
        n1=n1*10+(a[i]-'0');
        n2=n2*10+(a[i]-'0');
        if(n1>=252)
            n1=n1%252;
        if(n2>=525)
            n2=n2%525;
    }
    if(n1==0)
        printf("Yes ");
    else
        printf("No ");
    if(n2==0)
        printf("Yes\n");
    else
        printf("No\n");
}


return 0;
}



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
ll i,j,k,l,n1,n2,m,t,T,f,p,ans,cnt,par,ele;
char x,a[100005];
s(t);
while(t--)
{
    n1=0;
    n2=0;
    scanf("%s",a);
    l=strlen(a);
    FOR(l)
    {
        n1=n1*10+(a[i]-'0');
        n2=n2*10+(a[i]-'0');
        if(n1>=252)
            n1=n1%252;
        if(n2>=525)
            n2=n2%525;
    }
    if(n1==0)
        printf("Yes ");
    else
        printf("No ");
    if(n2==0)
        printf("Yes\n");
    else
        printf("No\n");
}


return 0;
}



