#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vi graph(101);
    for (int i = 1; i <= 100; i++) graph[i] = i;

    while (n--) {
        int x, y; cin >> x >> y;
        graph[x] = y;
    }

    while (m--) {
        int u, v; cin >> u >> v;
        graph[u] = v;
    }

    vi dist(101, -1);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while (q.size()) {
        int cur = q.front(); q.pop();
        for (int i = 1; i <= 6; i++) {
            if (cur+i > 100) continue;
            int nxt = graph[cur+i];
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }

    cout << dist[100];
}