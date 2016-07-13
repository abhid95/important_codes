//Problem: https://code.google.com/codejam/contest/189252/dashboard#s=p1&a=1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define EPS 1e-10
#define DEPS 1e-10
#define ld long double
ld ans, dans, low, high, x[1005], y[1005], z[1005], vx, vy, vz;
ll t, _t, i, n, cnt;
ld mid1, mid2, d1, d2, d3, tx, ty, tz;
ld eval(ld tm) {
    ld x, y, z;
    x = tx + vx*tm;
    y = ty + vy*tm;
    z = tz + vz*tm;
    return sqrt((x)*(x) + (y)*(y) + (z)*(z));
}
int main() {
    cin>>t;
    for(_t = 1; _t <= t; _t++) {
        cin>>n;
        tx = ty = tz = vx = vy = vz = 0;
        for(i = 0; i < n; i++) {
            cin>>x[i]>>y[i]>>z[i];
            tx += x[i];
            ty += y[i];
            tz += z[i];
            cin>>x[i]>>y[i]>>z[i];
            vx += x[i];
            vy += y[i];
            vz += z[i];
        }
        tx /= n;
        ty /= n;
        tz /= n;
        if(fabs(vx) <= DEPS && fabs(vy) <= DEPS && fabs(vz) <= DEPS) {
            dans = sqrt(tx*tx+ty*ty+tz*tz);
            ans = 0;
        }
        else {
            vx /= n;
            vy /= n;
            vz /= n;
            low = 0;
            high = 1e9;
            cnt = 0;
            while(high - low > EPS) {
                mid1 = (low*2 + high)/3;
                mid2 = (low + high*2)/3;
                d1 = eval(mid1);
                d2 = eval(mid2);

                if(d1 < d2) high = mid2;
                else low = mid1;

                cnt++;
            }
            ans = low;
            dans = eval(ans);
        }
        //if(dans*(1e6) - ((ll)(dans*(1e5)))*10 > 5)
           // dans += 0.000001;
        //if(ans*(1e6) - ((ll)(ans*(1e5)))*10 > 5)
           // ans += 0.00001;
        printf("Case #%lld: %.8Lf %.8Lf\n", _t, dans, ans);
    }

    return 0;
}


