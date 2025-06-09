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
    vector<int> dist(n + 1, inf);
    vector<bool> inq(n + 1, false);
    
    while(m--) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({w, b});
    }
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        inq[cur] = false;
        for (auto [w, v] : g[cur]) {
            if (dist[v] > dist[cur] + w) {
                dist[v] = dist[cur] + w;
                if (inq[v]) continue;
                q.push(v), inq[v] = true;
            }
        }
    }
    if (dist[n] == inf) cout << "impossible" << endl;
    else cout << dist[n] << endl;
    
}

 
int main() {
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}