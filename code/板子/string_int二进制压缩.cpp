#include <bits/stdc++.h>
using namespace std;
#define fast ios ::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
typedef long long ll;
#define REP(i, s, e) for (int i = (s); i < (e); ++i)
#define OUT(v) for (int k = 0; k < v.size(); ++k) cout << v[k] << ' '; cout << endl;
const int N = 1e5 + 10;
int h[N], e[2 * N], ne[N];

// 质数判断
bool ckp(int x) {
    if (x <= 1) return false;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int ten(string s) {
    int res = 0, len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] == '1') {
            res += pow(2, len - i - 1);
        }
    }
    return res;
}

int main() {
    string s = "0111";
    cout << ten(s);
    return 0;
}
