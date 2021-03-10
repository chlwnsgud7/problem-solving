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
        int n, m; cin >> n >> m;

        int N = n+m+1;
        vi tree(4*N);
        vi arr(N);
        vi idx(n+1);

        function<void(int, int, int, int)> update = [&] (int t, int i, int l, int r) -> void {
            if (l == r) {
                tree[i] = arr[t];
                return;
            }

            int m = (l+r) / 2;
            if (t <= m) update(t, i*2, l, m);
            else update(t, i*2+1, m+1, r);
            tree[i] = tree[i*2] + tree[i*2+1];
        };

        function<int(int, int, int, int, int)> query = [&] (int b, int e, int i, int l, int r) -> int {
            if (e < l || b > r) return 0;
            if (b <= l && r <= e) return tree[i];
            int m = (l+r) / 2;
            return query(b, e, i*2, l, m) + query(b, e, i*2+1, m+1, r);
        };

        for (int i = 1; i <= n; i++) {
            idx[i] = n+1 - i;
            arr[i] = 1;
            update(i, 1, 1, N);
        }

        for (int q = 1; q <= m; q++) {
            int cur; cin >> cur;

            int rst = query(idx[cur]+1, n+q-1, 1, 1, N);
            cout << rst << " ";

            arr[idx[cur]] = 0;
            update(idx[cur], 1, 1, N);

            idx[cur] = n+q;
            arr[idx[cur]] = 1;
            update(idx[cur], 1, 1, N);
        }
        cout << "\n";
    }
}