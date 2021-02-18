#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

inline bool valid(int x, int n) {
    return 0 <= x && x < n;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

template <typename T>
inline T pop(queue<T>& q) {
    T front = q.front();
    q.pop();
    return front;
}

template <typename T>
inline T gcd(T a, T b) {
    for (; b; a %= b, swap(a, b));
    return a; 
}

template <typename T>
tuple<T, T, T> xgcd(T a, T b) {
    if (b == 0) return {1, 0, a};
    T x, y, g;
    tie(x, y, g) = xgcd(b, a%b);
    return {y, x-(a/b)*y, g};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, w; cin >> n >> w;
        vvi a(n+2, vi(2));
        for (int j = 0; j < 2; j++) for (int i = 1; i <= n; i++) cin >> a[i][j];
        int rst = 2*n;
        vvi dp(n+2, vi(3));

        auto calc = [&] (int beg) -> void {
            for (int i = beg; i <= n+1; i++) {
                dp[i][0] = min(dp[i-1][1]+1, dp[i-1][2]+1);
                if (a[i-1][0] + a[i-1][1] <= w) dp[i][0] = min(dp[i][0], dp[i-1][0]+1);
                if (a[i-2][0] + a[i-1][0] <= w && a[i-2][1] + a[i-1][1] <= w) dp[i][0] = min(dp[i][0], dp[i-2][0]+2);

                dp[i][1] = dp[i][0] + 1;
                if (a[i-1][0] + a[i][0] <= w) dp[i][1] = min(dp[i][1], dp[i-1][2]+1);

                dp[i][2] = dp[i][0] + 1;
                if (a[i-1][1] + a[i][1] <= w) dp[i][2] = min(dp[i][2], dp[i-1][1]+1);
            }
        };

        // N ~ 1 / 2N ~ N+1 연결 안 됨
        dp[1][0] = 0;
        dp[1][1] = 1;
        dp[1][2] = 1;
        calc(2);
        rst = min(rst, dp[n+1][0]);
        //cout << "type0: " << dp[n+1][0] << "\n";

        if (a[n][0] + a[1][0] <= w) {
            // N ~ 1만 연결
            for (int i = 0; i < n+2; i++) dp[i].clear();
            dp[2][0] = 1;
            dp[2][1] = 2;
            dp[2][2] = (a[1][1] + a[2][1] <= w) ? 1 : 2;
            calc(3);
            rst = min(rst, dp[n][2] + 1);
            //cout << "type1: " << dp[n][2]+1 << "\n";
        }

        if (a[n][1] + a[1][1] <= w) {
            // 2N ~ N+1만 연결
            for (int i = 0; i < n+2; i++) dp[i].clear();
            dp[2][0] = 1;
            dp[2][1] = (a[1][0] + a[2][0] <= w) ? 1 : 2;
            dp[2][2] = 2;
            calc(3);
            rst = min(rst, dp[n][1] + 1);
            //cout << "type2: " << dp[n][1]+1 << "\n";
        }

        if (a[n][0] + a[1][0] <= w && a[n][1] + a[1][1] <= w) {
            // N ~ 1 / 2N ~ N+1 모두 연결
            for (int i = 0; i < n+2; i++) dp[i].clear();
            dp[2][0] = 0;
            dp[2][1] = 1;
            dp[2][2] = 1;
            calc(3);
            rst = min(rst, dp[n][0] + 2);
            //cout << "type3: " << dp[n][0] + 2 << "\n";
        }

        cout << rst << "\n";
    }

    // 참고한 풀이: https://casterian.net/archives/1356
}