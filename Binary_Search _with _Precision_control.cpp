//Problem: https://code.google.com/codejam/contest/11274486/dashboard#s=p2

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
int mod = 1000000007;
#define LOW_RATE -1.000000000001
#define HIGH_RATE 1.000000000001
#define MAX_ITERATION 10000
#define PRECISION_REQ 0.0000000001
long double computeIRR(long double cf[], long long numOfFlows)
{
 long long i = 0,j = 0;
 long double m = 0.0;
 long double old = 0.00;
 long double new1 = 0.00;
 long double oldguessRate = LOW_RATE;
 long double newguessRate = LOW_RATE;
 long double guessRate = LOW_RATE;
 long double lowGuessRate = LOW_RATE;
 long double highGuessRate = HIGH_RATE;
 long double npv = 0.0;
 long double denom = 0.0;
 for(i=0; i<MAX_ITERATION; i++)
 {
  npv = 0.00;
  for(j=0; j<numOfFlows; j++)
  {
   denom = pow((1 + guessRate),j);
   npv = npv + (cf[j]/denom);
  }
   /* Stop checking once the required precision is achieved */
  if((npv > 0) && (npv < PRECISION_REQ))
   break;
  if(old == 0)
   old = npv;
  else
   old = new1;
  new1 = npv;
  if(i > 0)
  {
   if(old < new1)
   {
    if(old < 0 && new1 < 0)
     highGuessRate = newguessRate;
    else
     lowGuessRate = newguessRate;
   }
   else
   {
    if(old > 0 && new1 > 0)
     lowGuessRate = newguessRate;
    else
     highGuessRate = newguessRate;
   }
  }
  oldguessRate = guessRate;
  guessRate = (lowGuessRate + highGuessRate) / 2;
  newguessRate = guessRate;
 }
 return guessRate;
}
int main() {
	int t,tno=0;
	cin>>t;
	while(t--){
		
		int n;
		cin>>n;
		long double cf[30], irr = 0.0000000000000000;
		int numOfFlows=n+1;
		
		for(int i=0;i<=n;i++)
		{
			cin>>cf[i];
			if(i==0)
				cf[0]*=-1;
		}
		irr = computeIRR(cf, numOfFlows);
		cout<<"Case #"<<++tno<<": ";
		cout<<setprecision(20)<<fixed<<irr<<endl;
		//printf("%.20llf\n", irr);
		
		
		
		
	}
	return 0;
}
