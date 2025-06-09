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

/*
kruskal
只需要对边的集合一次排序即可
而prim的优化版
需要实时的进行排序, 找到最小值

*/
vector<int> father;

int find(int u) {
    return (u == father[u] ? u : father[u] = find(father[u]));
}

void join(int a, int b) {
    int u = find(a);
    int v = find(b);
    if (u == v) return;
    father[u] = v;
}

bool same(int a, int b) {
    int u = find(a);
    int v = find(b);
    return u == v;
}


void solve() {
    int n, E;
    cin >> n >> E;
    father.assign(n + 1, 0);
    for (int i = 0; i <= n; ++i) father[i] = i;
    vector<pair<int, pii>> edges;
    while(E--) {
        int a, b, val;
        cin >> a >> b >> val;
        edges.push_back({val, {a, b}});
    }
    sort(edges.begin(),edges.end(), [](pair<int, pii> p1, pair<int, pii> p2){
        return p1.first < p2.first;
    });
    int cnt = 0;
    int res = 0;
    for(int i = 0; i < edges.size() && cnt < n - 1; i++) {
        auto [minval, edge] = edges[i];
        auto [a, b] = edge;
        if (same(a, b)) continue;
        join(a, b);
        ++cnt, res += minval;
    }
    cout << res;
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}

