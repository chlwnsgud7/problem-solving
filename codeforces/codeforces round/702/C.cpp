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
        ll x; cin >> x;
        bool ok = 0;
        for (ll a = 1; a*a*a < x; a++) {
            ll lo = 1;
            ll hi = 10001;
            ll b = -1;

            while (lo < hi) {
                ll mid = (lo + hi) / 2;
                if (a*a*a + mid*mid*mid < x) lo = mid+1;
                else if (a*a*a + mid*mid*mid > x) hi = mid;
                else {
                    b = mid;
                    break;
                }
            }

            if (b != -1) {
                ok = 1;
                break;
            }
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}