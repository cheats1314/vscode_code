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
    有个很关键的点是, cnt的更新.
    1.cnt的更新和v是否在队列中无关, 如果dist[v] > dist[cur] + w, 那cnt就可以更新
    2.cnt不能直接++, 像这样:cnt[v]++是错误的,因为如果有重边的情况.A3
      为了解决重边导致的错误, 由于每个点每次入队, 肯定是被前驱节点访问了
      cur是v的前驱节点, 所以:cnt[v] = cnt[cur] + 1;这样可以避免重边导致的错误cnt++.
      那为什么cnt[v] = cnt[cur] + 1能行, 原因是我们不关注cnt的实际意义, 只要保证有负环的情况cnt一定会累加到某个值.
      脑补一个负环, 三个节点, 对于每个节点入队时, cnt都会+1, 那么就能保证cnt会一直累加,这样到最后一定会达到某个值.
      条件: >=n
直接cnt++的hack样例:
5 8
// 1 2 1
// 1 3 1
// 1 5 5
// 2 4 1
// 2 5 4
// 3 5 -100
// 4 5 -200
// 4 3 -200
*/


bool spfa() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n + 1);
    vector<int> dist(n + 1, inf);
    vector<bool> inq(n + 1, false);
    vector<int> cnt(n + 1, 0);
    while(m--) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({w, b});
    }
    queue<int> q;
    dist[1] = 0;
    for (int i = 1; i <= n; ++i) q.push(i), inq[i] = true;
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        inq[cur] = false;
        for (auto [w, v] : g[cur]) {
            if (dist[v] > dist[cur] + w) {
                dist[v] = dist[cur] + w;
                cnt[v] = cnt[cur] + 1; // 这一步防止重边导致的错误
                if (cnt[v] >= n) return true;
                if (!inq[v]) {
                    q.push(v), inq[v] = true;
                }
            }
        }
    }
    
    return false;
}
void solve() {
    if (spfa()) cout << "Yes" << endl;
    else cout << "No" << endl;
}

// 


int main() {
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}