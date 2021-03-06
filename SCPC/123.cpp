#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int c = 1; c <= t; c++) {
        int n, k; cin >> n >> k;
        
        using vi = vector<int>;
        vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
        vi b(n); for (int i = 0; i < n; i++) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int rst = 0;
        for (int i = 0; i < k; i++) rst = max(rst, a[i]+b[k-1-i]);
        cout << "Case #" << c << "\n" << rst << "\n";
    }
}