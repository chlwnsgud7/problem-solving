#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int c = 1; c <= t; c++) {
        int n, k; cin >> n >> k;

        using vi = vector<int>;
        vi x(n+1); for (int i = 1; i <= n; i++) cin >> x[i];
        vi y(n+1); for (int i = 1; i <= n; i++) cin >> y[i];

        vi px(n+1); for (int i = 1; i <= n; i++) px[i] = px[i-1] + x[i];
        vi py(n+1); for (int i = 1; i <= n; i++) py[i] = py[i-1] + y[i];

        using vvi = vector<vi>;
        vvi dp(n+1, vi(n+1));
        vvi psum(n+1, vi(n+1));

        dp[0][0] = 1;
        psum[0][0] = 1;

        
    }
}