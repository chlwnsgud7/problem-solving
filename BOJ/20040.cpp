#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m; cin >> n >> m;
    
    vi root(n);
    for (int i = 0; i < n; i++) root[i] = i;

    function<int(int)> find = [&] (int i) -> int {
        if (i != root[i]) root[i] = find(root[i]);
        return root[i];
    };

    function<bool(int, int)> merge = [&] (int a, int b) -> bool {
        a = find(a); b = find(b);
        if (a == b) return false;
        root[a] = b;
        return true;
    };
    
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        if (!merge(a, b)) {
            cout << i;
            return 0;
        }
    }

    cout << 0;
}