#include <Header.h>


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


