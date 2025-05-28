
import sys
import bisect

def solve():
    data = sys.stdin.read().split()
    n, k = map(int, data[:2])
    nums = list(map(int, data[2:]))

    # 用一个有序列表 window 来模拟 multiset
    window = sorted(nums[:k])
    lit = [window[0]]     # 存放每个窗口的最小值
    big = [window[-1]]    # 存放每个窗口的最大值

    for i in range(k, n):
        # 删除滑出窗口的元素
        x = nums[i - k]
        idx = bisect.bisect_left(window, x)
        window.pop(idx)

        # 插入新进窗口的元素
        bisect.insort(window, nums[i])

        # 记录当前窗口的最小／最大
        lit.append(window[0])
        big.append(window[-1])

    # 输出结果
    print(*lit)
    print(*big)

if __name__ == "__main__":
    solve()
