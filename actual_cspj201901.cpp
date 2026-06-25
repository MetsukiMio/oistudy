#include <iostream>

using namespace std;

int main() {
    string ss;
    cin >> ss;
    int i = 0;
    for (auto ch : ss) {
        if (ch == '1') {
            ++i;
        }
    }
    cout << i;
}
