#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cur_i = -1;
    for (int i = 0; i < 3; i++) {
        string input;
        cin >> input;
        if (input[0] != 'F' && input[0] != 'B') {
            cur_i = stoi(input);
        }
        if (cur_i != -1) {
            cur_i++;
        }
    }
    if (cur_i % 3 == 0 && cur_i % 5 == 0) {
        cout << "FizzBuzz\n";
    } else if (cur_i % 3 == 0) {
        cout << "Fizz\n";
    } else if (cur_i % 5 == 0) {
        cout << "Buzz\n";
    } else {
        cout << cur_i << "\n";
    }
    return 0;
}
