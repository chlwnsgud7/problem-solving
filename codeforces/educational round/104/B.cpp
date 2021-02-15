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
        ll n, k; cin >> n >> k;
        k--;
        if (n % 2 == 0) cout << (k%n) + 1 << "\n";
        else {
            // n==3, [1, 3, 2], 1, 3, 2, ...
            //        3  2  1
            // n==5, [1, 2, 4, 5, 2, 3, 5, 1, 3, 4], 1, 2, 4, 5, ...
            //        5     3     1     4     2
            // n==7, [1, 2, 3, 5, 6, 7, 2, 3, 4, 6, 7, 1, 3, 4, 5, 7, 1, 2, 4, 5, 6], 1, 2, 3, 5, ...
            //        7        4        1        5        2        6        3

            ll loop = n/2 * n;
            k %= loop;
            ll a = k / (n/2);
            ll b = k % n;

            cout << ((a*n) + a + b) % n + 1 << "\n";
        }
    }
}