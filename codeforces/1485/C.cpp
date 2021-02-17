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

    int t; cin >> t;
    while (t--) {
        ll x, y; cin >> x >> y;

        // special한 갯수가 y-1이 되는 경우 -> x >= y * (y-1) + y-1 (x == 0인 경우가 제외되므로)
        // y == 1인 경우는 아예 제외됨 -> 나머지가 0이고 몫도 0 -> x == 0
        
        ll lo = 1;
        ll hi = y+1;
        ll spe = 1;
        while (lo < hi) {
            ll mid = (lo+hi) / 2;
            if (x >= mid*mid-1) {
                spe = max(spe, mid);
                lo = mid+1;
            }
            else {
                hi = mid;
            }
        }

        ll rst = spe*(spe-1)/2;
        //cout << "spe:" << spe << "\n";

        // special한 쌍의 갯수를 제한해보자
        // special한 갯수가 y-k가 되려면 -> x >= y * (y-k) + y-k;
        // 여기서부터는 x는 전 범위, y는 점점 커짐
        // special한 갯수가 spe가 되려면 -> x >= y * spe + spe;
        
        ll lasty = spe+1;
        for (ll cur = spe-1; cur > 0; cur--) {
            ll lo = lasty;
            ll hi = y+1;
            ll nxty = lasty-1;
            while (lo < hi) {
                ll mid = (lo+hi) / 2;
                if (x >= mid*cur + cur) {
                    nxty = max(nxty, mid);
                    lo = mid+1;
                }
                else {
                    hi = mid;
                }
            }

            //cout << "cur: " << cur << " " << lasty << " " << nxty << "\n";
            rst += (cur) * (nxty - lasty + 1);
            lasty = nxty+1;
        }

        cout << rst << "\n";
    }
}