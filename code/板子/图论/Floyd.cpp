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
// 例题:
// https://kamacoder.com/problempage.php?pid=1155

void solve() {
    int n, m;
    cin >> n >> m;
    viii g(n + 1, vii(n + 1, vi(n + 1, inf)));
    while(m--) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b][0] = w;
        g[b][a][0] = w;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j][k] = min(g[i][j][k - 1], g[i][k][k - 1] + g[k][j][k - 1]);
            }
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        if (g[a][b][n] == inf) cout << -1 << endl;
        else cout << g[a][b][n] << endl;
    }
}


int main() {
    int t = 1;
    while(t--) solve();
    return 0;
}