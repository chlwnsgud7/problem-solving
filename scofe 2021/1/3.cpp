#include <bits/stdc++.h>
using namespace std;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int N; cin >> N;
    vvi grid(N+1, vi(N+1));
    for (int i = 1; i <= N; i++) {
        string row; cin >> row;
        for (int j = 1; j <= N; j++) {
            grid[i][j] = row[j-1] - '0';
        }
    }
    
    vvi dp(N+1, vi(N+1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (grid[i][j]) {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
            }
        }
    }

    vi rst(N+1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= dp[i][j]; k++) rst[k]++;
        }
    }
    for (int i = 1; i <= N; i++) rst[0] += rst[i];

    cout << "total: " << rst[0] << "\n";
    for (int i = 1; i <= N; i++) {
        if (!rst[i]) return 0;
        cout << "size[" << i << "]" << ": " << rst[i] << "\n";
    }
}