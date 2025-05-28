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


struct State {
    int a, b;
    bool operator<(State const& o) const {
        if (o.a != a) return o.a < a;
        else return o.b < b;
    }
};

void solve() {
    priority_queue<State> pq;
    pq.push({4, 5});
    pq.push({4, 2});
    pq.push({3, 5});
    pq.push({3, 2});
    pq.push({5, 3});
    while(!pq.empty()) {
        auto[a, b] = pq.top();
        pq.pop();
        cout << a << ' ' << b << endl;
    }
}


int main() {
    int t = 1;
    while(t -- ) solve();
    return 0;
}




