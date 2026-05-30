#include <fmt/base.h>
#include <fmt/format.h>
#include <utility>

void bubble_sort(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    int a[] = {0, 5, 3, 9, 1, 8, 9, 7};
    bubble_sort(a, 8);
    for (int i = 0; i < 8; i++)
    {
        fmt::println("{}", a[i]);
    }
}
