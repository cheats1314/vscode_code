#include <bits/stdc++.h>
using namespace std;
#define fast ios ::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
typedef long long ll;
#define REP(i, s, e) for (int i = (s); i < (e); ++i)
#define OUT(v) for (int k = 0; k < v.size(); ++k) cout << v[k] << ' '; cout << endl;
const int N = 1e5 + 10;
int h[N], e[2 * N], ne[N];


class Date {
public:
    const int rq[13] = {29, 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};  // r[2]平年, rq[0] 是闰年
    bool check(int yy) {
        return ((yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0));
    }
    int yy, mm, dd;
    Date(int year, int month, int day) {  // 不带默认值的构造函数
        yy = year, mm = month, dd = day;
    }
    void nextDay() {
        if ((!check(yy) && dd == rq[mm]) || (check(yy) && mm == 2 ? dd == rq[0] : dd == rq[mm])) {
            dd = 1, mm++;
            if (mm > 12) mm = 1, yy++;
        } else dd++;
    }
    bool isSame(Date d) {
        return d.getDay() == dd && d.getMonth() == mm && d.getYear() == yy;
    }
    void print() const { printf("%d-%02d-%02d\n", yy, mm, dd); }
    int getYear() const { return yy; }
    int getMonth() const { return mm; }
    int getDay() const { return dd; }
};


int main() {
    int yy = 2023, mm = 12, dd = 1;   // 起始日期
    int YY = 2024, MM = 12, DD = 31;  // 结束日期
    Date start(yy, mm, dd);
    Date end(YY, MM, DD);
    while (true) {
        start.print();
        if (start.isSame(end)) break;
        start.nextDay();
    }
    return 0;
}