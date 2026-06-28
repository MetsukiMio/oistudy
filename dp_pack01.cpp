#include <iostream>
#include <cstring>
#include <cstdint>

using namespace std;

int n, t;
uint16_t tcost[3404], mget[3404];
int dp[3400004];

int main() {
    cin >> t >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tcost[i] >> mget[i];

        for (int j = t; j >= tcost[i]; --j) {
            dp[j] = max(dp[j], dp[j - tcost[i]] + mget[i]);
        }
    }

    cout << dp[t] << endl;

    return 0;
}
