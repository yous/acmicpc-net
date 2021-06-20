#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S;
    int sum = 0;
    int num = 0;
    bool subtracting = false;
    for (char ch : S) {
        switch (ch) {
            case '+':
                if (subtracting) {
                    sum -= num;
                } else {
                    sum += num;
                }
                num = 0;
                break;
            case '-':
                if (subtracting) {
                    sum -= num;
                } else {
                    subtracting = true;
                    sum += num;
                }
                num = 0;
                break;
            default:
                int digit = ch - '0';
                num = num * 10 + digit;
                break;
        }
    }
    if (subtracting) {
        sum -= num;
    } else {
        sum += num;
    }
    cout << sum << "\n";
    return 0;
}
