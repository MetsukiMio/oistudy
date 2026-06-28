#include <iostream>
#include <cstring>
#include <cstdint>

using namespace std;

int n, t;
uint16_t tcost[3404], mget[3404];
int16_t mem[3404][12882];

// 主函数: f(p, tl)
// f(p, tl) = max(
//                f(p + 1, tl),
//                f(p + 1, tl - t[p]) + m[p]
//
int dp(int pos, int tleft) {
    if (mem[pos][tleft] != -1) {
        return mem[pos][tleft];
    }

    if (pos == n + 1) {
        mem[pos][tleft] = 0;
        return 0;
    }

    int dp2 = -1;
    int dp1 = dp(pos + 1, tleft); // 跳过
    if (tleft >= tcost[pos]) {
        dp2 = dp(pos + 1, tleft - tcost[pos]) + mget[pos];
    }

    mem[pos][tleft] = max(dp1, dp2);
    return mem[pos][tleft];
}

int main() {
    memset(mem, -1, sizeof(mem));
    cin >> t >> n;
    for (int i = 1; i <= n; i++) cin >> tcost[i] >> mget[i];
    cout << dp(1, t) << endl;
    return 0;
}
