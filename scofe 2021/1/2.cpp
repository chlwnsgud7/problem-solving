#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    string A; cin >> A;

    using ll = long long;
    using vi = vector<ll>;
    vi dp(101);
    dp[1] = 1;
    for (int i = 2; i <= 100; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    ll rst = 1;
    int cur = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == '0') {
            rst *= dp[cur];
            cur = 0;
            continue;
        }
        cur++;
    }
    if (cur) rst *= dp[cur];
    cout << rst;
}