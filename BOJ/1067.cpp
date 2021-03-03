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

/* FFT Demo */
/* 출처 : https://justicehui.github.io/hard-algorithm/2019/09/04/FFT/ */

typedef complex<double> cpx;
typedef vector<cpx> vec;

const double pi = acos(-1);

/*
input : f => Coefficient, w => principal n-th root of unity
output : f => f(x_0), f(x_1), f(x_2), ... , f(x_n-1)
T(N) = 2T(N/2) + O(N)
*/
void FFT(vec &f, cpx w){
	int n = f.size();
	if(n == 1) return; //base case
	vec even(n >> 1), odd(n >> 1);
	for(int i=0; i<n; i++){
		if(i & 1) odd[i >> 1] = f[i];
		else even[i >> 1] = f[i];
	}
	FFT(even, w*w); FFT(odd, w*w);
	cpx wp(1, 0);
	for(int i=0; i<n/2; i++){
		f[i] = even[i] + wp * odd[i];
		f[i+n/2] = even[i] - wp * odd[i];
		wp = wp * w;
	}
}

/*
input : a => A's Coefficient, b => B's Coefficient
output : A * B
*/
vec mul(vec a, vec b){
	int n = 1;

  //a * b 결과의 길이보다 길거나 같은 2의 멱수 찾기
	while(n <= a.size() || n <= b.size()) n <<= 1;
	n <<= 1;
	a.resize(n); b.resize(n); vec c(n);

  //principal n-th root of unity
	cpx w(cos(2*pi/n), sin(2*pi/n));

  //a와 b의 dft구하기
	FFT(a, w); FFT(b, w);

  //f(x) * g(x) = h(x)
	for(int i=0; i<n; i++) c[i] = a[i] * b[i];

  //켤레 복소수로 dft -> idft
	FFT(c, cpx(w.real(), -w.imag()));
	for(int i=0; i<n; i++){
		c[i] /= cpx(n, 0);
		c[i] = cpx(round(c[i].real()), round(c[i].imag())); // 만약 정수 결과를 원한다면
	}
	return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

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