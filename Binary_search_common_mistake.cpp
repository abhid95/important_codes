//Problem: https://code.google.com/codejam/contest/1150485/dashboard#s=p1

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define EPS 1e-6
bool res;
ll t, i, c, _t;
ld low, high, mid, d, p[100005], v[100005];
bool go(ld tm) {
    ld pos = 0;
    for(ll i = 0; i < c; i++) {
        if(i == 0 || pos < p[i]-tm) pos = p[i]-tm;
        pos = pos + v[i]*d;
        if(pos-d > p[i]+tm) return 0;
    }
    return 1;
}
int main() {
    cin>>t;
    for(_t = 1; _t <= t; _t++) {
        cin>>c>>d;
        for(i = 0; i < c; i++) {
            cin>>p[i]>>v[i];
        }
        low = 0;
        high = 1e12;
        while((high - low) > EPS) {
            mid = (low+high)/2;
            res = go(mid);
            if(res) high = mid;
            else low = mid;
            //printf("%.20Lf %.20Lf %.20Lf\n", mid, low, high);
        }
        printf("Case #%lld: %Lf\n", _t, low);
    }

    return 0;
}


