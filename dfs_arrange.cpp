#include <bitset>
#include <fmt/format.h>
#include <iostream>

int n, arr[10];
std::bitset<10> status = {};

void bfs_arrange(int index)
{
    if (index > n)
    {
        for (int i = 1; i <= n; i++)
        {
            fmt::print("{} ", arr[i]);
        }
        fmt::println("");
        return;
    }

    for (int current = 1; current <= n; current++)
    {
        if (status[current])
        {
            continue;
        }
        status.set(current);
        arr[index] = current;

        bfs_arrange(index + 1);
        status.set(current, false);
    }
}

int main()
{
    std::cin >> n;
    bfs_arrange(1);
}
