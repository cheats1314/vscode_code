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
// 优先队列优化, 复杂度为O()
void solve() {
    int n, E;
    cin >> n >> E;
    vector<vector<pii>> g(n + 1);
    while(E--) {
        int a, b, val;
        cin >> a >> b >> val;
        g[a].emplace_back(val, b);
        g[b].emplace_back(val, a);
    }
    vector<int> minDist(n + 1, inf);
    vector<int> inTree(n + 1, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(inf, 1);
    while(!pq.empty()) {
        auto [minval, cur] = pq.top();
        pq.pop();
        if (inTree[cur]) continue;
        inTree[cur] = true;
        for (auto [val, v] : g[cur]) {
            if (!inTree[v]) {
                minDist[v] = min(minDist[v], val);
                pq.push({minDist[v], v});
            }
        }
    }
    int res = 0;
    // OUT(minDist);
    for (int i = 2; i <= n; ++i) res += minDist[i];
    cout << res;
}
 
int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}