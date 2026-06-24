#include <iostream>

using namespace std;

int nums[1000][1000];

int main()
{
    int layers;
    cin >> layers;
    for (int i = 1; i <= layers; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> nums[i][j];
        }
    }
    cout << "test" << endl;
}
