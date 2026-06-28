#include <iostream>
#include <cstring>
#include <cstdint>

using namespace std;

constexpr int MAXN = 1e4 + 5;
constexpr int MAXW = 1e7 + 5;

int n, T;
int t[MAXN], v[MAXN];
int64_t f[MAXW];

int main() {
    cin >> T >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> v[i];

        for (int j = t[i]; j <= T; ++j) {
            f[j] = max(f[j], f[j - t[i]] + v[i]);
        }
    }

    cout << f[T] << endl;

    return 0;
}
