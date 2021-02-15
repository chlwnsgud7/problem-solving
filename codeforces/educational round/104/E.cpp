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

    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;

    vll a(n1); for (int i = 0; i < n1; i++) cin >> a[i];
    vll b(n2); for (int i = 0; i < n2; i++) cin >> b[i];
    vll c(n3); for (int i = 0; i < n3; i++) cin >> c[i];
    vll d(n4); for (int i = 0; i < n4; i++) cin >> d[i];

    int m1; cin >> m1; vector<pair<int, int>> t1(m1);
    for (int i = 0; i < m1; i++) {
        cin >> t1[i].first >> t1[i].second;
    }
    int m2; cin >> m2; vector<pair<int, int>> t2(m2);
    for (int i = 0; i < m2; i++) {
        cin >> t2[i].first >> t2[i].second;
    }
    int m3; cin >> m3; vector<pair<int, int>> t3(m3);
    for (int i = 0; i < m3; i++) {
        cin >> t3[i].first >> t3[i].second;
    }

    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    sort(t3.begin(), t3.end());

    vll dist1(n1, 1e12), dist2(n2, 1e12), dist3(n3, 1e12), dist4(n4, 1e12);
    priority_queue<vll> pq;
    for (int i = 0; i < n1; i++) {
        dist1[i] = a[i];
        pq.push(vll{-a[i], 1, i});
    }

    ll sub = 0;
    ll sub2 = 0;
    ll sub3 = 0;
    ll sub4 = 0;

    while (pq.size()) {
        vll top = pq.top(); pq.pop();
        int idx = top[2];
        ll cost = -top[0];
        if (top[1] == 2) if (dist2[idx] < -top[0]) continue;
        if (top[1] == 3) if (dist3[idx] < -top[0]) continue;

        if (top[1] == 1 && sub2 < n2) {
            for (int i = 0; i < n2; i++) {
                if (*lower_bound(t1.begin(), t1.end(), pii(idx+1, i+1)) == pii(idx+1, i+1)) continue;
                if (dist2[i] > cost + b[i]) {
                    if (dist2[i] == 1e12) sub2++;
                    dist2[i] = cost + b[i];
                    pq.push(vll{-dist2[i], 2, i});
                }
            }
        }
        if (top[1] == 2 && sub3 < n3) {
            for (int i = 0; i < n3; i++) {
                if (*lower_bound(t2.begin(), t2.end(), pii(idx+1, i+1)) == pii(idx+1, i+1)) continue;
                if (dist3[i] > cost + c[i]) {
                    if (dist3[i] == 1e12) sub3++;
                    dist3[i] = cost + c[i];
                    pq.push(vll{-dist3[i], 3, i});
                }
            }
        } 
        if (top[1] == 3) { 
            for (int i = 0; i < n4; i++) {
                if (*lower_bound(t3.begin(), t3.end(), pii(idx+1, i+1)) == pii(idx+1, i+1)) continue;
                if (dist4[i] > cost + d[i]) {
                    if (dist4[i] == 1e12) sub++;
                    dist4[i] = cost + d[i];
                }
            }
        }
        sub4++;

        if (sub == n4 || sub4 > 2e8) {
            ll rst = 1e12;
            for (int i = 0; i < n4; i++) rst = min(rst, dist4[i]);  
            cout << rst;
            return 0;    
        }
    }

    ll rst = 1e12;
    for (int i = 0; i < n4; i++) rst = min(rst, dist4[i]);
    if (rst == 1e12) rst = -1;
    cout << rst;
}