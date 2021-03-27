#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int e; cin >> e;

        int graph[101][101] = {};
        while (e--) {
            char tmp;
            int a, b;
            cin >> tmp >> a >> tmp >> b;

            graph[a][b] = 1;
            graph[b][a] = 1;
        }

        char tmp;
        int tgt;
        cin >> tmp >> tgt;
        
        int rst[101] = {};
        for (int i = 1; i <= 100; i++) {
            if (graph[tgt][i]) {
                rst[i] = 1;
                for (int j = 1; j <= 100; j++) {
                    if (j == tgt) continue;
                    if (graph[i][j]) {
                        rst[j] = 1;
                    }
                }
            }
        }

        int rst2 = 0;
        for (int i = 1; i <= 100; i++) if (rst[i]) rst2++;
        cout << "The number of supervillains in 2-hop neighborhood of v" << tgt << " is " << rst2 << "\n";
    }
}