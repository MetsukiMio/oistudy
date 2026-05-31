#include <fmt/format.h>
#include <iostream>
#include <vector>

int k[200];
int steps[200];
std::vector<int> needChecks;

int main()
{
    int n, a, b;
    std::cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> k[i];
        steps[i] = -1;
    }

    steps[a] = 0;
    needChecks.push_back(a);

    int currentSteps = 1;
    while (!needChecks.empty())
    {
        std::vector<int> nextChecks;
        for (int i : needChecks)
        {
            if (i + k[i] <= n && steps[i + k[i]] == -1)
            {
                steps[i + k[i]] = currentSteps;
                nextChecks.push_back(i + k[i]);
            }
            if (i - k[i] >= 1 && steps[i - k[i]] == -1)
            {
                steps[i - k[i]] = currentSteps;
                nextChecks.push_back(i - k[i]);
            }
        }
        needChecks.swap(nextChecks);

        currentSteps++;
    }

    std::cout << steps[b] << std::endl;
}
