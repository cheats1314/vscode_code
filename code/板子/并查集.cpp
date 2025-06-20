#include <bits/stdc++.h>
using namespace std;
#define fast ios ::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
using ll = long long;
#define OUT(v) for (int k = 0; k < v.size(); ++k) cout << v[k] << ' '; cout << endl;
const int N = 1e5 + 10;
int h[N], e[2 * N], ne[N];

vector<int> father;

void init(int size) {
    father.resize(size + 1);
    for (int i = 0; i < size + 1; i++) {
        father[i] = i;
    }
}
int find(int u) {
    return u == father[u] ? u : father[u] = find(father[u]);
}
bool same(int a, int b) {
    a = find(a);
    b = find(b);
    return a == b;
}
void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    father[b] = a;
}


int main() {
    int n, m;
    cin >> n >> m;
    return 0;
}