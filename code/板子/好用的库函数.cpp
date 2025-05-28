#include <bits/stdc++.h>
using namespace std;
#define fast ios ::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
using ll = long long;
#define OUT(v) for (int k = 0; k < v.size(); ++k) cout << v[k] << ' '; cout << endl;
const int N = 1e5 + 10;
int h[N], e[2 * N], ne[N];
//ceil: 向上取整
//log2: 以二为底的对数
// accumulate  返回指定范围内元素的总和, 参数: (起始位置, 终止位置, 初始值)
//  upper_bound (a, a + n, target) 二分查找, 找到第一个大于指定元素的位置, 返回值是指定元素的地址
// lower_bound (a, a + n, target) 查找第一个大于等于指定元素的位置, 返回值是指定元素的地址
// upper_bound (a, a + n, target) - 1: 第一个小于指定元素的位置
// lower_bound (a, a + n, target) - 1: 第一个小于等于指定元素的位置
// max_element (a.begin(), a.end())返回数组中的最大元素
//__builtin_popcount 计算二进制中1的个数
// decltype: decltype 关键字也可以用于类型推导，但它更侧重于在编译时获取表达式的类型
// isdigit: 判断单个字符是否为数字, 参数char
// atoi: 把一个数字构成的字符串转为int 类型返回.字符串的首个字符可以是+或者-. 用法:int num = atoi(str.c_str());
// next_permutation 函数用于将范围 [first, last) 中的元素重新排序为下一个字典序更大的排列
// operator 用法
// 用于重载运算符, 下面给出重载 '<'运算符的实例
struct State { // 结构体存储需要维护的三个值
    int a;
    int b;
    int c;
    bool operator<(State const& o) const { // 按照升序, 依次对a, b, c三个元素进行排序
        if (o.a != a) return o.a < a;
        else if (o.b != b) return o.b < b;
        else return o.c < c;
    }
};

int main() {
    priority_queue<State> q;
    return 0;
}

