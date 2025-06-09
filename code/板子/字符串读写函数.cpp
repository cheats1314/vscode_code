#include <bits/stdc++.h>
using namespace std;
#define fast ios ::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
using ll = long long;
typedef pair<int, int> PII;
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



//stringstream 头文件是: sstream
/*
std::setw 和 std::setfill 是流的状态设置，它们只对下一次插入操作生效，之后流的状态会恢复到默认值。
如果需要对多个数据进行相同的格式化，必须在每次插入之前重新设置这些状态。
*/

int main() {
    stringstream ss;
    int year = 2024;
    int month = 2;
    int day = 25;
    ss << year << "-" << setw(2) << setfill('0') << month << '-'
       << setw(2) << setfill('0') << day;
    string s = ss.str(); // 转为string类型
    cout << ss.str();
}


