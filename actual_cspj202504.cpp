#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n, k;
ll a[N], s[N];
// id => 值到右端点映射
ll id[2005000], lst = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    // s => [0, a[0], a[0] ^ a[1], a[0] ^ a[1] ^ a[2], ...]
    for (int i = 1; i <= n; i++)
        cin >> a[i], s[i] = s[i - 1] ^ a[i];
    memset(id, -1, sizeof(id));
    id[0] = 0;
    ll ans = 0;
    for (int r = 1; r <= n; r++)
    {
        // x = s[l] (if true)
        ll x = s[r] ^ k;
        if (id[x] >= lst)
        {
            ans++;
            lst = r;
        }
        id[s[r]] = r;
    }
    cout << ans;
    return 0;
}
