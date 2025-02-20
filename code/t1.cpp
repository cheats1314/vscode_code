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
int mul(int x, int y) {return 1LL * x * y % MOD; }
int fact[N], ifact[N];

int fastpow(int x, int y) {
    int res = 1;
    while(y) {
        if (y &  1) res = mul(res, x);
        x = mul(x, x), y >>= 1;
    }
    return res;
}

int C(int n, int m) {
    if (m == 0 || m == n) return 1;
    return mul(fact[n], mul(ifact[m], ifact[n-m]));
}


void solve() {
    int n;
    string s;
    cin >> n >> s;
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = mul(i, fact[i-1]);
    ifact[n] = fastpow(fact[n], MOD - 2);
    for (int i = n; i >= 1; i--) ifact[i-1] = mul(i, ifact[i]);
    
    vector<int> win(n + 1), fail(n + 1);
    for (int i = 0; s[i]; i++) {
        if (s[i] == '0') fail[i+1]=fail[i]+1, win[i+1]=win[i];
        else win[i+1]=win[i]+1, fail[i+1]=fail[i];
    }
    bool status = true;
    for (int i = 1; i <= n; i++) {
        if (fail[i] > win[i]) {
            status = false;
            break;
        }
    }
    if (status) cout << n;
    else {
        for (int i = 1; i <= n; i++) {
            if (fail[i] - win[i] > 2) {
                cout << 0;
                return;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (fail[i] > win[i]) {
                cout << fail[i];
                break;
            }
        }
    }
}

signed main() {
    fast;
    solve();
    return 0;
}
