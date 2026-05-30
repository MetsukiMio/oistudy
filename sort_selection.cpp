#include <fmt/format.h>

void selection_sort(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        int minidx = i;
        for (int j = i; j < length; j++)
        {
            if (arr[j] < arr[i])
            {
                minidx = j;
            }
        }

        if (minidx != i)
        {
            std::swap(arr[i], arr[minidx]);
        }
    }
}

int main()
{
    int a[] = {0, 4, 6, 6, 5, 8, 6, 4};
    selection_sort(a, 8);
    for (int i = 0; i < 8; i++)
    {
        fmt::println("{}", a[i]);
    }
}
