#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int left_min = 1e9;
    int right_min = 1e9;
    bool is_left = true;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num == -1) {
            is_left = false;
            continue;
        }
        if (is_left) {
            left_min = min(left_min, num);
        } else {
            right_min = min(right_min, num);
        }
    }
    cout << left_min + right_min << "\n";
    return 0;
}
