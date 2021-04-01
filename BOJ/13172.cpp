#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll mod = 1e9 + 7;

ll fastpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    ll sub = fastpow(a, b/2);
    ll rst = sub * sub % mod;
    if (b % 2) rst = rst * a % mod;
    return rst;
}

int main() {
    int m; cin >> m;
    ll rst = 0;
    while (m--) {
        ll n, s; cin >> n >> s;
        rst += fastpow(n, mod-2) * s % mod;
        rst %= mod;
    }
    cout << rst;
}