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

void solve(vi& arr, vi& rst, int step) {
    int maxv = 0;
    int maxi = 0;
    int n = arr.size();
    if (n == 0) return;

    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[maxi]) {
            maxi = i;
            maxv = arr[i];
        }
    }

    rst = vi(n);
    rst[maxi] = step;

    vi left(arr.begin(), arr.begin()+maxi);
    vi right(arr.begin()+maxi+1, arr.end());
    vi lrst, rrst;
    solve(left, lrst, step+1);
    solve(right, rrst, step+1);

    for (int i = 0; i < left.size(); i++) rst[i] = lrst[i];
    for (int i = 0; i < right.size(); i++) rst[i+maxi+1] = rrst[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
        vi rst;
        solve(a, rst, 0);
        for (int x : rst) cout << x << " ";
        cout << "\n";
    }
}