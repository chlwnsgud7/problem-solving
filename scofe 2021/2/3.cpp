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

void dfs(int cur, vvi& graph, vi& dfsnum, vi& dfsend, int& step) {
    dfsnum[cur] = ++step;
    for (int nxt : graph[cur]) {
        if (dfsnum[nxt]) continue;
        dfs(nxt, graph, dfsnum, dfsend, step);
    }
    dfsend[cur] = step;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, q; cin >> n >> q;
    vi par(n+1);
    vvi graph(n+1);

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        par[b] = a;
        graph[a].push_back(b);
    }

    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (par[i] == 0) root = i;
    }
    
    vi dfsnum(n+1), dfsend(n+1);
    int step = 0;
    dfs(root, graph, dfsnum, dfsend, step);

    while (q--) {
        int a, b; cin >> a >> b;
        if (dfsnum[a] <= dfsnum[b] && dfsnum[b] <= dfsend[a]) cout << "yes\n";
        else cout << "no\n";
    }
}