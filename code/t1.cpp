#include <bits/stdc++.h>
using namespace std;
#define fast ios ::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
using ll = long long;
#define int long long
#define OUT(v)                         \
    for (int k = 0; k < v.size(); ++k) \
        cout << v[k] << ' ';           \
    cout << endl;
const int N = 1e5 + 10;
int h[N], e[2 * N], ne[N];
const int MOD = 1e9 + 7;


void solve() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int> > a(n);
        for (int i = 0; i < n; i++) {
            a[i].resize(n);
            for (int j = 0; j < n; j++) cin >> a[i][j];
            sort(begin(a[i]), end(a[i]));
        }
        vector<vector<int> > b(n);
        b[0].resize(1);
        b[0][0] = a[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] >= a[i-1][0] && b[i].size() < i + 1) {
                    b[i].push_back(a[i][j]);
                }
            }
        }
        // 验证
        for (int i = 0; i < n; i++) OUT(b[i]);
    }
}


signed main() {
    fast;
    solve();
    return 0;
}
