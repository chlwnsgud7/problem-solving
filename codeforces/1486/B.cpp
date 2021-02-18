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
        vpii a(n); 
        for (auto& [x,y] : a) cin >> x >> y;
        
        multiset<ll> xs, ys;
        for (auto& [x, y] : a) {
            xs.insert(x);
            ys.insert(y);
        }

        ll x;
        if (xs.size() % 2) x = 1;
        else {
            auto it = xs.begin();
            for (int i = 0; i < xs.size()/2-1; i++) ++it;
            x = *next(it) - *it + 1;
        }

        ll y;
        if (ys.size() % 2) y = 1;
        else {
            auto it = ys.begin();
            for (int i = 0; i < ys.size()/2-1; i++) ++it;
            y = *next(it) - *it + 1;
        }

        cout << x*y << "\n";
    }
}