#include <bits/stdc++.h>

using namespace std;

int i = 0;
int n[5005];
const int MOD = 998244353;

int cnt1[5001] = {0};
int cnt2[5001 * 5000] = {0};
int dp(int *arr, int count, int mm) {
    int maxsum = 0;
    for (int a = 0; a < count; a++) {
        maxsum += arr[a];
    }
    memset(cnt1, 0x00, sizeof(int) * 5001);
    memset(cnt2, 0x00, sizeof(int) * 5001);

    for (int a = 0; a < count; a++) {
        int x = arr[a];

        // check this!
        for (int s = maxsum; s >= x; --s) {
            cnt2[s] = (cnt2[s] + cnt1[s - x] + cnt2[s - x]) % MOD;
        }
        cnt1[x] = (cnt1[x] + 1) % MOD;
    }

    int result = 0;
    for (int s = mm + 1; s <= maxsum; s++) {
        result += cnt2[s];
    }

    return result % MOD;
}

int main() {
    cin >> i;
    for (int j = 1; j <= i; j++) {
        cin >> n[j];
    }

    std::sort(&n[1], &n[i + 1], [](int a, int b) { return a > b; });

    int ans = 0;
    for (int j = 1; j <= i - 2; j++) {
        int max = n[j];
        int startIdx = j + 1;
        int ll = i - j;

        ans += dp(&n[startIdx], ll, max);
    }

    cout << ans % MOD << endl;
}
