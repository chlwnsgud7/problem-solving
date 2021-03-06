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

    int n; cin >> n;
    ll a, b, c; cin >> a >> b >> c;

    vll x(n+1); for (int i = 1; i <= n; i++) cin >> x[i];
    vll psum(n+1); for (int i = 1; i <= n; i++) psum[i] = psum[i-1] + x[i];
    
    struct line {
        ll a, b; 
        line(ll a, ll b): a(a), b(b) {}
    };
    vector<line> lines;
    
    auto cx = [] (const line& l, const line& m) -> double {
        return 1.0 * (m.b-l.b) / (l.a-m.a);
    };
    
    auto insert = [&lines, &cx] (const line& v) -> void {
        while (lines.size() >= 2 && cx(*(lines.rbegin()+1), *lines.rbegin()) > cx(*lines.rbegin(), v))  {
            lines.pop_back();
        }
        lines.push_back(v);
    };
    
    auto find = [&lines, &cx] (ll x) -> ll {
        ll lo = 0;
        ll hi = lines.size()-1;
    
        while (lo < hi) {
            ll mid = (lo + hi) / 2;
            if (cx(lines[mid], lines[mid+1]) <= x) lo = mid+1;
            else hi = mid;
        }
        return lines[lo].a * x + lines[lo].b;
    };

    vll dp(n+1);
    insert(line(b, 0));
    for (int i = 1; i <= n; i++) {
        dp[i] = c + a*psum[i]*psum[i] + find(psum[i]);
        insert(line(-2*a*psum[i]+b, dp[i]+a*psum[i]*psum[i]-b*psum[i]));
    }
    cout << dp[n];
}