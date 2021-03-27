#include <bits/stdc++.h>
using namespace std;
using vs = vector<string>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

int main() {
    int n; cin >> n;
    vs input(n);
    getline(cin, input[0]);
    for (int i = 0; i < n; i++) {
        getline(cin, input[i]);
    }

    map<string, int> m;
    for (int i = 0; i < n; i++) {
        stringstream ss;
        ss.str(input[i]);

        string a, b; ss >> a >> b;
        if (!m[a]) m[a] = m.size();
        if (!m[b]) m[b] = m.size();
    }
    

    vector<vvll> graph(m.size()+1);
    for (int i = 0; i < n; i++) {
        stringstream ss;
        ss.str(input[i]);

        string a, b; ss >> a >> b;
        int c; ss >> c;
        graph[m[a]].push_back(vll{m[b], c});
        graph[m[b]].push_back(vll{m[a], c});
    }

    vll root(m.size()+1);
    for (int i = 0; i < root.size(); i++) root[i] = i;

    function<int(int)> find = [&] (int i) -> int {
        if (i != root[i]) root[i] = find(root[i]);
        return root[i];
    };

    function<void(int, int)> merge = [&] (int a, int b) -> void {
        a = find(a);
        b = find(b);
        root[a] = b;
    };

    priority_queue<vll> pq;
    for (int i = 1; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int nxt = graph[i][j][0];
            int cost = graph[i][j][1];
            pq.push(vll{-cost, i, nxt});
        }
    }

    ll rst = 0;
    while (pq.size()) {
        vll top = pq.top(); pq.pop();
        int cost = -top[0];
        int a = top[1];
        int b = top[2];

        if (find(a) == find(b)) continue;
        merge(a, b);
        rst += cost;
    }

    cout << rst;
    return 0;
}