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

struct node {
    int idx = 0;
    int count = 0;
    bool exist = 0;
    node* child[26] = {};
    node* fail;
};

void dfs(node* cur, vi& rst) {
    if (cur->exist) {
        rst[cur->idx] = cur->count;
    }
    for (int i = 0; i < 26; i++) {
        if (cur->child[i]) dfs(cur->child[i], rst);
    }
}

void dfs2(node* cur) {
    for (int i = 0; i < 26; i++) {
        if (cur->child[i]) dfs2(cur->child[i]);
    }
    delete cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int q; cin >> q;
    vs sq(q); for (int i = 0; i < q; i++) cin >> sq[i];
    int n; cin >> n;
    vs sn(n); for (int i = 0; i < n; i++) cin >> sn[i];

    node* trie = new node;
    for (int i = 0; i < q; i++) {
        string s = sq[i];
        node* cur = trie;

        for (char c : s) {
            int idx = c - 'a';
            if (!cur->child[idx]) cur->child[idx] = new node;
            cur = cur->child[idx];
        }

        cur->exist = 1;
        cur->idx = i;
    }

    trie->fail = trie;
    queue<node*> qn; qn.push(trie);
    while (qn.size()) {
        node* cur = qn.front(); qn.pop();
        for (int i = 0; i < 26; i++) {
            if (!cur->child[i]) continue;
            node* child = cur->child[i];
            node* fail = cur->fail;
            if (cur != trie) {
                while (fail != trie && !fail->child[i]) {
                    fail = fail->fail;
                }
                if (fail->child[i]) fail = fail->child[i];
            }

            child->fail = fail;
            if (fail->exist) child->exist = 1;
            qn.push(child);
        }
    }

    vi rst(q);
    for (int i = 0; i < n; i++) {
        string s = sn[i];
        node* cur = trie;
        vb sub(q);
        bool rst = 0;

        for (char c : s) {
            int idx = c-'a';
            while (cur != trie && !cur->child[idx]) cur = cur->fail;
            if (cur->child[idx]) cur = cur->child[idx];
            if (cur->exist) {
                rst = 1;
            }
        }
        if (rst) cout << "YES\n";
        else cout << "NO\n";
    }
}