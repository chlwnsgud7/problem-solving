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

    using cpx = complex<double>;
    using vec = vector<cpx>;
    const double pi = 3.14159265358979;

    function<vec(vec, vec)> mul = [pi] (vec a, vec b) -> vec {
        function<void(vec&, cpx)> FFT = [&FFT](vec& f, cpx w) -> void {
            int n = f.size();
            if (n == 1) return;

            vec even(n>>1), odd(n>>1);
            for (int i = 0; i < n; i++) {
                if (i & 1) odd[i>>1] = f[i];
                else even[i>>1] = f[i];
            }
            FFT(even, w*w); FFT(odd, w*w);
            cpx wp(1, 0);
            for (int i = 0; i < n/2; i++) {
                f[i] = even[i] + wp*odd[i];
                f[i+n/2] = even[i] - wp*odd[i];
                wp = wp * w;
            }
        };

        int n = 1;
        while (n <= a.size() || n <= b.size()) n <<= 1;
        n <<= 1;
        a.resize(n); b.resize(n); vec c(n);

        cpx w(cos(2*pi/n), sin(2*pi/n));
        FFT(a, w); FFT(b, w);
        for (int i = 0; i < n; i++) c[i] = a[i] * b[i];

        FFT(c, cpx(w.real(), -w.imag()));
        for (int i = 0; i < n; i++) {
            c[i] /= cpx(n, 0);
            c[i] = cpx(round(c[i].real()), round(c[i].imag())); /* 정수 결과 필요시 */
        }

        return c;
    };

    int n; cin >> n;
    vi x(n); for (int i = 0; i < n; i++) cin >> x[i];
    vi y(n); for (int i = 0; i < n; i++) cin >> y[i];

    vec a(2*n); for (int i = 0; i < 2*n; i++) a[i] = x[i%n];
    vec b(n); for (int i = 0; i < n; i++) b[i] = y[n-1-i];

    vec c = mul(a, b);
    double rst = 0;
    for (int i = n; i <= 2*n; i++) rst = max(rst, c[i].real());
    cout << fixed << setprecision(0) << rst;
}

// 풀이 출처 : https://justicehui.github.io/hard-algorithm/2019/09/04/FFT/