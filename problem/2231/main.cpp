#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int calc(int num) {
    int result = num;
    while (num > 0) {
        result += num % 10;
        num /= 10;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int order = 0;
    int tmp = N;
    while (tmp > 0) {
        order++;
        tmp /= 10;
    }
    bool found = false;
    for (int i = N - 9 * order; i <= N - order; i++) {
        if (calc(i) == N) {
            cout << i << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "0\n";
    }
    return 0;
}
