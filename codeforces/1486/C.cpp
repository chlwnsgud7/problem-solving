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
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); cout.tie(NULL);
    // C1 & C2

    int n; cin >> n;
    
    cout << "? 1 " << n << endl; 
    int piv; cin >> piv;

    int sub; 
    if (piv != 1) {
        cout << "? 1 " << piv << endl;
        cin >> sub;
    }
    else {
        sub = 0;
    }
    
    int lo, hi, rst;
    if (sub == piv) {
        lo = 1;
        hi = piv-1;
        rst = (lo+hi)/2;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            cout << "? " << mid << " " << piv << endl;
            cin >> sub;

            if (sub == piv) {
                rst = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
    }
    else {
        lo = piv+1;
        hi = n;
        rst = (lo+hi)/2;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            cout << "? " << piv << " " << mid << endl;
            cin >> sub;

            if (sub == piv) {
                rst = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
    }
    cout << "! " << rst << endl;
}