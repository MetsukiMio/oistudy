#include <fmt/format.h>
#include <queue>
#include <iostream>

int w, h;
bool visited[100][100];
char map[100][100];

constexpr uint64_t compose(int x, int y)
{
    return static_cast<uint64_t>(x) << 32 | static_cast<uint64_t>(y);
}

constexpr int decomposeX(uint64_t c)
{
    return static_cast<int>(c >> 32);
}

constexpr int decomposeY(uint64_t c)
{
    return static_cast<int>(c);
}

void markPos(int x, int y, std::queue<uint64_t> &q) {
    if (!(x <= 0 && y <= 0 && x > w && y > h) && !visited[x][y] && map[x][y] == '.') {
        visited[x][y] = true;
	q.push(compose(x, y));
    }
}

int main()
{
    std::queue<uint64_t> ntcks;
    std::cin >> w >> h;
    for (int a = 1; a <= w; a++) {
        for (int b = 1; b <= h; b++) {
	    std::cin >> map[a][b];
	}
    }

    ntcks.push(compose(1, 1));

    while (!ntcks.empty()) {
        auto pos = ntcks.front();
        ntcks.pop();
        auto posx = decomposeX(pos);
        auto posy = decomposeY(pos);
	if (posx == w && posy == h) {
	    fmt::println("Yes");
	    return 0;
	}

        markPos(posx, posy + 1, ntcks);
        markPos(posx, posy - 1, ntcks);
        markPos(posx + 1, posy, ntcks);
        markPos(posx - 1, posy, ntcks);
    }

    fmt::println("No");
}
