#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    using vs = vector<string>;
    
    vs start(N), end(N);
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> start[i] >> tmp >> end[i];
    }
    
    sort(start.rbegin(), start.rend());
    sort(end.begin(), end.end());
    if (start[0] > end[0]) {
        cout << -1;
        return 0;
    }
    cout << start[0] << " ~ " << end[0];
}