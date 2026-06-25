#include <iostream>

using namespace std;

int main() {
    int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    std::string ss;
    cin >> ss;

    for (auto ch : ss) {
        if ('0' <= ch && ch <= '9') {
            arr[ch - '0']++;
        }
    }

    for (int j = 9; j >= 0; j--) {
        while (arr[j] > 0) {
            cout << j;
            arr[j]--;
        }
    }
}
