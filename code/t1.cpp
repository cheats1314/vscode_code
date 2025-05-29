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
        int s, e, val;
        cin >> s >> e >> val;
        g[s].push_back({val, e});
    }
    vector<int> minDist(n + 1, inf);
    minDist[1] = 0;

    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto [val, v] : g[cur]) {
            minDist[v] = min(minDist[v], minDist[cur] + val);
            q.push(v);
        }
    }
    if (minDist[n] == inf) cout << "unconnected" << endl;
    else cout << minDist[n] << endl;
}
 
 
int main() {
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}