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
        vll a(n+1); for (int i = 1; i <= n; i++) cin >> a[i];
        vll b(m); for (int i = 0; i < m; i++) cin >> b[i];

        vll psum(n+1);
        for (int i = 1; i <= n; i++) psum[i] = psum[i-1] + a[i];

        if (psum[n] > 0) {
            map<ll, ll> hey;
            for (int i = 1; i <= n; i++) {
                if (hey.lower_bound(psum[i]) != hey.end()) continue;
                hey[psum[i]] = i-1;
            }

            ll maxH = hey.rbegin()->first;
            ll loop = psum[n];

            for (int i = 0; i < m; i++) {
                ll cur = b[i];
                if (cur <= maxH) {
                    auto it = hey.lower_bound(cur);
                    cout << it->second << " ";
                }
                else {
                    ll lo = 0;
                    ll hi = cur / loop + 5;
                    ll k = hi;

                    while (lo < hi) {
                        ll mid = (lo + hi) / 2;
                        if (mid*loop + maxH >= cur) {
                            k = min(k, mid);
                            hi = mid;
                        }
                        else lo = mid+1;
                    }

                    cur -= k*loop;
                    auto it = hey.lower_bound(cur);
                    cout << it->second + k*n << " ";
                }
            }
        }
        else {
            map<ll, ll> hey;
            for (int i = 1; i <= n; i++) {
                if (hey.lower_bound(psum[i]) != hey.end()) continue;
                if (hey[psum[i]]) continue;
                hey[psum[i]] = i-1;
            }

            for (int i = 0; i < m; i++) {
                auto it = hey.lower_bound(b[i]);
                if (it == hey.end()) cout << "-1 ";
                else cout << it->second << " ";
            }
        }
        cout << "\n";
    }
}