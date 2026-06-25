#include <bits/stdc++.h>

using namespace std;

int i = 0;
int n[5005];
bool f[5005] = {false};
const int mod = 998244353;

bool hasTwoOnesOrMore(int n) {
    return n && (n & (n - 1));
}

int main() {
    cin >> i;
    for (int j = 1; j <= i; j++) {
        cin >> n[j];
    }

    std::sort(&n[1], &n[i + 1], [](int a, int b) { return a > b; });

    uint64_t ans = 0;
    for (int j = 1; j <= i - 2; j++) {
        int max = n[j];
        int startIdx = j + 1;
        int ll = i - j;

        // solve this!
        for (uint64_t mask = 0; mask < std::pow(2, ll); ++mask) {
            if (!hasTwoOnesOrMore(mask)) {
                continue;
            }

            int sum = 0;
            for (int k = 0; k < ll; k++) {
                if ((mask >> k) & 1) {
                    sum += n[startIdx + k];
                }

                if (sum > max) {
                    ++ans;
                    break;
                }
            }
        }
    }

    cout << ans % mod << endl;
}
