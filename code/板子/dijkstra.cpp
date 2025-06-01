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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n + 1);
    while(m--) {
        int s, e, v;
        cin >> s >> e >> v;
        g[s].push_back({v, e});
    }
    vector<int> dist(n + 1, inf);
    vector<bool> us(n + 1, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()) {
        auto [minval, cur] = pq.top(); pq.pop();
        if (us[cur]) continue;
        us[cur] = true;
        for (auto& it : g[cur]) {
            int v = it.second, val = it.first;
            if (!us[v] && dist[v] > dist[cur] + val) {
                dist[v] = dist[cur] + val;
                pq.push({dist[v], v});
            }
        }
    }
    cout << (dist[n] == inf ? -1 : dist[n]);
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}

