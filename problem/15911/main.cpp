#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> coins(N);
    int front_cnt = 0;
    int half_cnt = 0;
    for (auto& num : coins) {
        char ch;
        int num1, num2;
        cin >> num1 >> ch >> num2;
        num = num1 * 1000000 + num2;
        if (num > 500000) {
            front_cnt++;
        } else if (num == 500000) {
            half_cnt++;
        }
    }
    if (half_cnt > 0) {
        cout << "SAME\n";
    } else if (front_cnt % 2 == 1) {
        cout << "ALIVE\n";
    } else {
        cout << "DEAD\n";
    }
    for (int i = 0; i < M; i++) {
        char ch;
        int idx, num1, num2;
        cin >> idx >> num1 >> ch >> num2;
        int old_num = coins[idx - 1];
        if (old_num > 500000) {
            front_cnt--;
        } else if (old_num == 500000) {
            half_cnt--;
        }
        int num = num1 * 1000000 + num2;
        coins[idx - 1] = num;
        if (num > 500000) {
            front_cnt++;
        } else if (num == 500000) {
            half_cnt++;
        }
        if (half_cnt > 0) {
            cout << "SAME\n";
        } else if (front_cnt % 2 == 1) {
            cout << "ALIVE\n";
        } else {
            cout << "DEAD\n";
        }
    }
    return 0;
}
