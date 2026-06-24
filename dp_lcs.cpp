#include "fmt/format.h"
#include <iostream>

using namespace std;

std::string a, b;
bool exists[1000][1000];
int results[1000][1000];

int dp(int i, int j)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }

    if (exists[i][j])
    {
        return results[i][j];
    }

    exists[i][j] = true;
    results[i][j] = a[i] == b[j] ? dp(i - 1, j - 1) + 1 : max(dp(i - 1, j), dp(i, j - 1));
    return results[i][j];
}

int main()
{
    cin >> a >> b;
    fmt::println("{}", dp(a.size() - 1, b.size() - 1));
}
