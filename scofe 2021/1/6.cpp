#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    int n, m; cin >> m >> n;
    vvi grid(n+1, vi(m+1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> grid[i][j];
    }

    vvi dp(n+1, vi(m+1, -1));
    dp[1][1] = grid[1][1];
    function<ll(int, int)> solve = [&] (int i, int j) -> ll {
        if (dp[i][j] == -1) {
            dp[i][j] = 0;
            if (i-1 >= 1) dp[i][j] = max(dp[i][j], solve(i-1, j));
            if (j-1 >= 1) dp[i][j] = max(dp[i][j], solve(i, j-1));
            dp[i][j] += grid[i][j];
        }
        return dp[i][j];
    };

    cout << solve(n, m);
}