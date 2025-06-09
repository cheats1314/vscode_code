#include <Header.h>

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
