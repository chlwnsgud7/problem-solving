#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
int main() {
    int n, m; cin >> m >> n;
    vs grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    int rst = 1e9;
    for (int c = 0; c < m; c++) {
        if (grid[0][c] == 'c') {
            vvi dist(n, vi(m, 1e9));
            dist[0][c] = 0;
            queue<int> qy, qx;
            qy.push(0);
            qx.push(c);

            while (qy.size()) {
                int cy = qy.front(); qy.pop();
                int cx = qx.front(); qx.pop();

                vi dy{1, 0, 0};
                vi dx{0, 1, -1};

                for (int d = 0; d < 3; d++) {
                    int ny = cy + dy[d];
                    int nx = cx + dx[d];
                    if (ny >= n || nx < 0 || nx >= m) continue;
                    if (dist[ny][nx] != 1e9) continue;
                    if (grid[ny][nx] == 'x') continue;

                    dist[ny][nx] = dist[cy][cx] + 1;
                    qy.push(ny);
                    qx.push(nx);
                }
            }

            for (int j = 0; j < m; j++) {
                rst = min(rst, dist[n-1][j]);
            }
        }
    }

    if (rst == 1e9) cout << -1;
    else cout << rst - (n-1);
}