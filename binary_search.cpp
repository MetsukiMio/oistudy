#include <fmt/base.h>
#include <fmt/format.h>

using namespace std;

int arr[10] = {0, 1, 2, 2, 2, 3, 4, 6, 7, 8};

int binary_search(int start, int end, int key)
{
    int ret = -1;
    int mid;
    while (start <= end)
    {
        // 找到中点
        mid = start + ((end - start) >> 1);
        if (arr[mid] < key)
            start = mid + 1;
        else if (arr[mid] > key)
            end = mid - 1;
        else
        {
            ret = mid;
            break;
        }
    }
    return ret;
}

int main()
{
    fmt::println("{}", binary_search(0, 10, 4));
}
