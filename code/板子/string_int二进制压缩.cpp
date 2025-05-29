#include <bits/stdc++.h>
using namespace std;
#define fast ios ::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
using ll = long long;
#define OUT(v) for (int k = 0; k < v.size(); ++k) cout << v[k] << ' '; cout << endl;
const int N = 1e5 + 10;
int h[N], e[2 * N], ne[N];


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
