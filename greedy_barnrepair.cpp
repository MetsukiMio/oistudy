#include <algorithm>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

int m, s, c;
uint8_t states[201];

constexpr uint8_t needed = 1;
constexpr uint8_t expected = 2;

int main()
{
    std::cin >> m >> s >> c;
    std::memset(&states[1], expected, s);
    for (int i = 1; i <= c; i++)
    {
        int ii;
        std::cin >> ii;
        states[ii] |= needed;
    }

    int pos = 1;
    while (states[pos] == expected)
    {
        states[pos] = 0;
        pos++;
    }

    pos = s;
    while (states[pos] == expected)
    {
        states[pos] = 0;
        pos--;
    }

    bool inside = false;
    pos = -1;
    std::vector<int> segs;
    int length = 0;
    for (int i = 1; i <= s; i++)
    {
        if (states[i] == 0)
        {
            continue;
        }

        length++;

        if (!inside && states[i] == expected)
        {
            pos = i;
            inside = true;
        }
        else if (inside && states[i] == (expected | needed))
        {
            segs.push_back(i - pos);
            inside = false;
        }
    }

    std::sort(segs.rbegin(), segs.rend());

    for (int i = 0; i < m - 1 && i < segs.size(); i++)
    {
        length -= segs[i];
    }

    std::cout << length << std::endl;
}
