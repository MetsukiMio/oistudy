#include <fmt/format.h>
#include <iostream>

int r[1000];

int main()
{
    int n;
    std::cin >> n;

    r[1] = 1;
    r[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        r[i] = r[i - 1] + r[i - 2];
    }

    fmt::println("{}", r[n]);
}
