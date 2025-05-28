#include <bits/stdc++.h>
using namespace std;

class Date {
public:
    const int days[13] = {0, 31, (leap(yy) ? 29 : 28), 31, 30, 31, 30,31, 31, 30, 31, 30, 31};  // [2]平年, [0] 是闰年
    bool leap(int y) {
        return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
    }
    Date(int y, int m, int d) {  // 不带默认值的构造函数
        yy = y, mm = m, dd = d;
    }
    int yy, mm, dd;
    void nextDay() {
        dd ++ ;
        if (dd > days[mm]) {
            dd = 1, mm ++ ;
            if (mm > 12) mm = 1, yy ++ ;
        }
    }
};


int main() {
    int yy = 2023, mm = 12, dd = 1;   // 起始日期
    Date start(yy, mm, dd);
    cout << start.dd << endl;
    start.nextDay();
    cout << start.dd << endl;
    return 0;
}