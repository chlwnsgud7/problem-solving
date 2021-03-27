#include <bits/stdc++.h>
using namespace std;

using vs = vector<string>;
using ll = long long;
using vll = vector<ll>;

int main() {
    int n; cin >> n;
    string hms; cin >> hms;
    vs a(n); for (string& s : a) cin >> s;
    
    for (int i = 0; i < hms.size(); i++) hms[i] -= '0';
    ll secs = (hms[0]*10+hms[1])*3600 + (hms[3]*10+hms[4])*60 + (hms[6]*10+hms[7]);
    vll b(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i].size(); j++) a[i][j] -= '0';
        b[i] = (a[i][0]*10+a[i][1])*60 + (a[i][3]*10+a[i][4]);
    }
    b.insert(b.begin(), 0);

    vll psum(n+1);
    for (int i = 1; i <= n; i++) psum[i] = psum[i-1] + b[i];

    //cout << secs << "\n";
    //for (ll x : b) cout << x << " "; cout << "\n";
    //for (ll p : psum) cout << p << " "; cout << "\n";
    
    vll rsts(n+1);
    for (int i = 1; i <= n; i++) {
        int lo = 1;
        int hi = i;
        int rst = i;
        while (lo <= hi) {
            int mid = (lo+hi) / 2;
            if (psum[i-1] - psum[mid-1] < secs) {
                rst = min(rst, mid);
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }
        rsts[i] = rst;
    }
    //for (int x : rsts) cout << x << " "; cout << "\n";

    vll sub(n+1);
    for (int i = 1; i <= n; i++) {
        sub[rsts[i]] = max(sub[rsts[i]], i-rsts[i]+1);
    }
    //for (int x : sub) cout << x << " "; cout << "\n";

    ll rsti = 0;
    ll rstv = 0;
    for (int i = 1; i <= n; i++) {
        if (rstv < sub[i]) {
            rstv = sub[i];
            rsti = i;
        }
    }
    cout << rstv << " " << rsti;
}