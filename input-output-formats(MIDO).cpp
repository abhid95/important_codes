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
int i,j,l,n,m,t,T,f,p,ans,cnt,par,ele,ap,a,bp,b,time,prev,opt,h,num,rem;
char x,str[10],sah[10],sam[10],sbh[10],sbm[10];
s(n);
ap=a=0;
bp=b=0;
prev=0;
FOR(n)
{
    s(opt);
    scanf("%d:%d",&h,&m);//without string processing
    //h=(str[0]-'0')*10+(str[1]-'0');
    //m=(str[3]-'0')*10+(str[4]-'0');
        time=h*60+m;
        //p(time);
        if(a>b)
            ap+=time-prev;
        else
            if(a<b)
            bp+=time-prev;
        //p(ap);
        //p(bp);
        prev=time;
    if(opt==1)
        a++;
    else
        b++;
}
time=48*60;
if(a>b)
    ap+=time-prev;
else if(a<b)
    bp+=time-prev;
//p(ap);
//p(bp);
/*num=ap/60;
rem=ap%60;
sah[1]=num%10+'0';
num/=10;
sah[0]=num%10+'0';
sam[1]=rem%10+'0';
rem/=10;
sam[0]=rem%10+'0';
num=bp/60;
rem=bp%60;
sbh[1]=num%10+'0';
num/=10;
sbh[0]=num%10+'0';
sbm[1]=rem%10+'0';
rem/=10;
sbm[0]=rem%10+'0';
sah[2]=sbh[2]=sam[2]=sbm[2]='\0';
printf("%s:%s\n",sah,sam);
printf("%s:%s\n",sbh,sbm);*/
printf("%02d:%02d\n",ap/60,ap%60);
printf("%02d:%02d\n",bp/60,bp%60);// important

return 0;
}



