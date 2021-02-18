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

    int n, m; cin >> n >> m;
    vvpii graph(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        graph[a].push_back(pii(b, w));
        graph[b].push_back(pii(a, w));
    }

    vector<map<int, ll>> graph2(n+1);
    for (int i = 1; i <= n; i++) {
        for (auto& [nxt, cost] : graph[i]) {
            for (auto& [nnxt, ncost] : graph[nxt]) {
                if (i == nnxt) continue;
                if (graph2[i][nnxt] == 0) graph2[i][nnxt] = (cost+ncost) * (cost+ncost);
                else graph2[i][nnxt] = min(graph2[i][nnxt], (ll)(cost+ncost) * (cost+ncost));
            }
        }
    }

    /*for (int i = 1; i <= n; i++) {
        for (auto& [nxt, dist] : graph2[i]) cout << i << " " << nxt << " " << dist << "\n";
    }*/

    priority_queue<vll> pq;
    vll dist(n+1, 1e18);
    dist[1] = 0;
    pq.push(vll{0, 1});

    while (pq.size()) {
        vll top = pq.top();
        pq.pop();

        if (dist[top[1]] < top[0]) continue;
        int cur = top[1];
        for (auto& [nxt, dis] : graph2[cur]) {
            if (dist[nxt] > dist[cur] + dis) {
                dist[nxt] = dist[cur] + dis;
                pq.push(vll{-dist[nxt], nxt});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == 1e18) dist[i] = -1;
        cout << dist[i] << " ";
    }
}