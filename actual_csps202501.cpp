#include <bits/stdc++.h>
using namespace std;

struct node
{
    int a, b, c;
};

void sol()
{
    int n;
    cin >> n;
    vector<node> a(n + 5);
    vector<int> b(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i].a >> a[i].b >> a[i].c;

    long long res = 0;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 1; i <= n; i++)
    {
        // select group a
        if (a[i].a >= max(a[i].b, a[i].c))
            b[i] = 1, res += a[i].a, cnt1++;
        // select group b
        else if (a[i].b >= max(a[i].a, a[i].c))
            b[i] = 2, res += a[i].b, cnt2++;
        // select group c
        else
            b[i] = 3, res += a[i].c, cnt3++;
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        // a overflow + a selection
        if (cnt1 > n / 2 && b[i] == 1)
            ans.push_back(a[i].a - max(a[i].b, a[i].c));
        // b overflow + b selection
        else if (cnt2 > n / 2 && b[i] == 2)
            ans.push_back(a[i].b - max(a[i].a, a[i].c));
        // c overflow + c selection
        else if (cnt3 > n / 2 && b[i] == 3)
            ans.push_back(a[i].c - max(a[i].a, a[i].b));
    }
    // sort + choose the largest ones
    sort(ans.begin(), ans.end());
    int i = 0;
    while (cnt1 > n / 2)
        res -= ans[i++], cnt1--;
    while (cnt2 > n / 2)
        res -= ans[i++], cnt2--;
    while (cnt3 > n / 2)
        res -= ans[i++], cnt3--;
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        sol();
}
