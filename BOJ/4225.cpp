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

#define x first
#define y second

pii operator-(pii& A, pii& B) {
    return {A.x-B.x, A.y-B.y};
}

int ccw(pii& A, pii& B, pii& C) {
    pii a = B - A;
    pii b = C - B;
    
    ll prod = (ll)a.x*b.y - (ll)a.y*b.x;
    if (prod) return prod / abs(prod);
    else return 0;
}

bool cross(pii& A, pii& B, pii& C, pii& D) {
    if (A == C || A == D || B == C || B == D) return 1;
    
    int abc = ccw(A, B, C);
    int abd = ccw(A, B, D);
    int cda = ccw(C, D, A);
    int cdb = ccw(C, D, B);
    
    if (abc*abd == 1) return 0;
    if (cda*cdb == 1) return 0;
    
    if (abc == 0 && abd == 0) {
        if (A.x != B.x) {
            int x1 = min(A.x, B.x);
            int x2 = max(A.x, B.x);
            int x3 = min(C.x, D.x);
            int x4 = max(C.x, D.x);
            
            if (x2 < x3 || x1 > x4) return 0;
        }
        else {
            int y1 = min(A.y, B.y);
            int y2 = max(A.y, B.y);
            int y3 = min(C.y, D.y);
            int y4 = max(C.y, D.y);
            
            if (y2 < y3 || y1 > y4) return 0;
        }
    }
    
    return 1;
}

vpii convex_hull(vpii points) {
    if (points.size() == 1) return points;
    
    sort(points.begin(), points.end());
    vpii up; up.reserve(points.size());
    for (pii& p : points) {
        up.push_back(p);
        while (up.size() >= 3) {
            auto a = up.end() - 3;
            auto b = up.end() - 2;
            auto c = up.end() - 1;
            if (ccw(*a, *b, *c) == -1) break;
            up.erase(b);
        }
    }
    
    reverse(points.begin(), points.end());
    vpii down; down.reserve(points.size());
    for (pii& p : points) {
        down.push_back(p);
        while (down.size() >= 3) {
            auto a = down.end() - 3;
            auto b = down.end() - 2;
            auto c = down.end() - 1;
            if (ccw(*a, *b, *c) == -1) break;
            down.erase(b);
        }
    }
    
    vpii cvxh; cvxh.reserve(points.size());
    cvxh.insert(cvxh.end(), up.begin(), up.end()-1);
    cvxh.insert(cvxh.end(), down.begin(), down.end()-1);
    return cvxh;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int tc = 1; ; tc++) {
        int n; cin >> n;
        while (!n) return 0;

        vpii a(n); for (auto& [x, y] : a) cin >> x >> y;
        vpii cvxh = convex_hull(a);

        /*cout << "CVXH\n";
        for (auto& [x, y] : cvxh) cout << x << " " << y << "\n";
        cout << "\n\n";*/

        int size = cvxh.size();
        double rst = 1e18;
        for (int i = 0, j = 1; i < size; i++, j=(j+1)%size) {
            double sub = 0.0;
            for (int k = 0; k < size; k++) {
                // 직선 ~ 점 거리 구하기
                double cur = [] (pii& a, pii& b, pii& c) -> double {
                    pii p = b - a;
                    pii q = c - a;

                    ll crs = p.x * q.y - p.y * q.x;
                    double nrm = sqrt(p.x * p.x + p.y * p.y);
                    return abs(crs / nrm);
                } (cvxh[i], cvxh[j], cvxh[k]);
                sub = max(sub, cur);
                //cout << cur << " ";
            }
            //cout << "\n";
            rst = min(rst, sub);
        }
        cout << "Case " << tc << ": " << fixed << setprecision(2) << rst+0.005 << "\n";
    }
}