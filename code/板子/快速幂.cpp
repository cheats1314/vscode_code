#include <bits/stdc++.h>
using namespace std;
#define fast ios ::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
using ll = long long;
#define int long long
int mul(int x, int y) {return 1LL * x * y % MOD; }
#define OUT(v)                         \
    for (int k = 0; k < v.size(); ++k) \
        cout << v[k] << ' ';           \
    cout << endl;
const int N = 1e5 + 10;
int h[N], e[2 * N], ne[N];
const int MOD = 1e9 + 7;



int fastpow(int x, int y) { // 快速进行幂运算
    int res = 1;
    while (y) {
      if (y & 1) res = mul(res, x);
      x = mul(x, x), y >>= 1;
    }
    return res;
}