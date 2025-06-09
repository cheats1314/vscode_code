#include <Header.h>

int fastpow(int x, int y) { // 快速进行幂运算
    int res = 1;
    while (y) {
      if (y & 1) res = mul(res, x);
      x = mul(x, x), y >>= 1;
    }
    return res;
}