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

    int T; cin >> T;
    while (T--) {
        ll a, b; cin >> a >> b;
        bool isone = 0;
        if (b == 1) {
            isone = 1;
            b++;
        }

        ll rst = 0;
        ll tmp = a;
        ll bnxt = b;
        while (tmp) {
            tmp /= bnxt;
            rst++;
        }

        while (1) {
            tmp = a;
            bnxt++;
            ll sub = bnxt - b;
            while (tmp) {
                tmp /= bnxt;
                sub++;
            }
            if (sub > rst) break;
            rst = min(rst, sub);
        }
        cout << rst + isone << "\n";
    }
}