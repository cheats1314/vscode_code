#include <bits/stdc++.h>
using namespace std;
#define fast ios ::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
typedef long long ll;
#define REP(i, s, e) for (int i = (s); i < (e); ++i)
#define OUT(v) for (int k = 0; k < v.size(); ++k) cout << v[k] << ' '; cout << endl;
const int N = 1e5 + 10;
int h[N], e[2 * N], ne[N];

// accumulate  返回指定范围内元素的总和, 参数: (起始位置, 终止位置, 初始值)
// lower_bound  返回指定范围内第一个不小于指定元素大小的元素的值
// max_element 返回数组中的最大元素
int main() {
    vector<int> a {1, 4, 5, 6, 8}; // c++11可以用这个语法
    int sum = accumulate(begin(a) +1, end(a), 0);
    vector<int>::iterator item = lower_bound(begin(a), end(a), 3);
    return 0;
}
