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

    ll n, a; cin >> n >> a;
    vvll xyw(n, vll(3));
    for (int i = 0; i < n; i++) cin >> xyw[i][0] >> xyw[i][1] >> xyw[i][2];

    sort(xyw.begin(), xyw.end(), [] (vll& a, vll& b) -> bool {
        return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
    });

    double sw = 0;
    double swd = 0;
    double rst = 0;

    for (int i = 0; i < n; i++) {
        auto d = [] (double x, double y) -> double { return sqrt(x*x+y*y); };
        double lo = d(xyw[i][0], xyw[i][1]);
        //cout << lo << " ";
        double hi = 2e9;
        if (i+1 < n) hi = d(xyw[i+1][0], xyw[i+1][1]);

        sw += xyw[i][2];
        swd += xyw[i][2] * d(xyw[i][0], xyw[i][1]);

        double A = -a;
        double B = sw;
        double C = -swd;

        double mid = -B / (2*A);
        //cout << mid << " ";

        auto f = [A, B, C] (double x) -> double { return A*x*x + B*x + C; };
        double sub = max(f(lo), f(hi));
        if (lo <= mid && mid <= hi) sub = max(sub, f(mid));
        rst = max(rst, sub);
    }
    cout << fixed << setprecision(6) << rst;
}