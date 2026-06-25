#include <cmath>
#include <iostream>

constexpr int MAXN = 10000;

int n, a[MAXN], d[MAXN];

int dp() {
    // d[n] => 数组截止到n的答案
    d[1] = 1;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        d[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] <= a[i]) {
                // 拼接, f(i) = max(f(i), f(j) + 1)
                d[i] = std::max(d[i], d[j] + 1);
                ans = std::max(ans, d[i]);
            }
    }
    return ans;
}

using namespace std;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cout << dp();
}
