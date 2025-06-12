#ifndef Fold
#include <bits/stdc++.h>
using namespace std;
#define fast ios ::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
using ll = long long;
using T3 = tuple<int, int, int>;
using A3 = array<int, 3>;
using V3 = vector<int>;
typedef pair<string, string> pss;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
#define OUT(v) {                                      \
    for (int k = 0; k < (v).size(); ++k) {             \
        if (k == v.size() - 1) cout << v[k];            \
        else cout << v[k] << ' ';                    \
    }                                                 \
    cout << endl;                                     \
}
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
ll mul(ll x, ll y) {return (1LL * x * y) % mod; }
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
int Dx[] = {0, -1, 0, 1, 1, -1, -1, 1}, Dy[] = {-1, 0, 1, 0, 1, -1, 1, -1};
#endif

// 例题: https://www.lanqiao.cn/problems/20139/learning/
int n, m;
vector<int> father, sz;
stack<pair<int, int>> road;

int find(int u) {
    return (u == father[u] ? u : find(father[u]));
}

void merge(int a, int b) {
    int u = find(a);
    int v = find(b);
    if (u == v) {
        road.push({-1, -1});
        return;
    }
    if (sz[u] > sz[v]) swap(u, v);
    father[u] = v;
    sz[v] += sz[u];
    road.push({u, v});
}

void bck() {
    if (!road.empty()) {
        auto [u, v] = road.top();
        road.pop();
        if (u == -1) return;
        father[u] = u;
        sz[v] -= sz[u];
    }
}

void solve() {
    fast;
    cin >> n >> m;
    father.resize(n + 1);
    sz.assign(n + 1, 1);
    for (int i = 0; i <= n; i++) father[i] = i;
    while(m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int u, v;
            cin >> u >> v;
            merge(u, v);
        }
        else if (op == 2) {
            bck();
        }
        else {
            int u, v;
            cin >> u >> v;
            if (find(u) == find(v)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}




