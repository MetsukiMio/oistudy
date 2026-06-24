#include <fmt/format.h>
#include <iostream>

int r[1000];
bool b[1000];

int fibo(int i)
{
    if (i < 2)
    {
        return 1;
    }

    if (b[i])
    {
        return r[i];
    }

    b[i] = true;
    r[i] = fibo(i - 1) + fibo(i - 2);
    return r[i];
}

int main()
{
    int n;
    std::cin >> n;

    fmt::println("{}", fibo(n));
}
