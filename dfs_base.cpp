#include <fmt/format.h>
#include <iostream>

int m, arr[103];

void dfs(int number, int segs, int begin)
{
    // number == 0, dfs 终点, 输出当前结果 (@arr, 1 ~ i-1)
    if (number == 0)
    {
        for (int j = 1; j <= segs - 1; ++j)
            fmt::print("{} ", arr[j]);
        fmt::print("\n");
    }

    // 分割段索引 segs 必须小于等于 m (边界条件)
    if (segs <= m)
    {
        for (int j = begin; j <= number; ++j)
        {
            // 分离当前位置
            // j => [a, number]
            arr[segs] = j;
            // 继续查找 number - j, 索引 segs + 1, 起始位置 j (后数大于前数)
            dfs(number - j, segs + 1, j);
        }
    }
}

int main()
{
    int n;
    std::cin >> n >> m;
    dfs(n, 1, 1);
}
