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
        int n; cin >> n;
        vvll a(n+1, vll(2)); for (int i = 1; i <= n; i++) {
            cin >> a[i][0];
            a[i][1] = i;
        }

        sort(a.begin(), a.end());
        vll psum(n+1);
        for (int i = 1; i <= n; i++) psum[i] = psum[i-1] + a[i][0];

        vll rst{a[n][1]};
        for (int i = n-1; i >= 1; i--) {
            if (psum[i] >= a[i+1][0]) rst.push_back(a[i][1]);
            else break;
        }

        sort(rst.begin(), rst.end());
        cout << rst.size() << "\n";
        for (ll x : rst) cout << x << " ";
        cout << "\n";
    }
}