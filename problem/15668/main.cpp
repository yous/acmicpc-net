#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(int target, int exp, int num1, int num2, vector<bool>& selected) {
    if (target == 0) {
        if (num1 > 0 && num2 > 0) {
            int zero_cnt = 0;
            int tmp = num1;
            while (tmp > 0) {
                if (tmp % 10 == 0) {
                    zero_cnt++;
                }
                tmp /= 10;
            }
            tmp = num2;
            while (tmp > 0) {
                if (tmp % 10 == 0) {
                    zero_cnt++;
                }
                tmp /= 10;
            }
            if (zero_cnt <= 1) {
                cout << num1 << " + " << num2 << "\n";
                exit(0);
            }
        }
        return;
    }
    int digit = target % 10;
    for (int i = 0; i <= 9; i++) {
        if (i != 0 && selected[i]) {
            continue;
        }
        selected[i] = true;
        if (digit - i >= 0) {
            if (digit - i == 0 || !selected[digit - i]) {
                selected[digit - i] = true;
                solve(target / 10, exp * 10, num1 + exp * i, num2 + exp * (digit - i), selected);
                selected[digit - i] = false;
            }
        } else {
            if (digit + 10 - i == 0 || !selected[digit + 10 - i]) {
                selected[digit + 10 - i] = true;
                solve(target / 10 - 1, exp * 10, num1 + exp * i, num2 + exp * (digit + 10 - i), selected);
                selected[digit + 10 - i] = false;
            }
        }
        selected[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<bool> selected(10);
    solve(N, 1, 0, 0, selected);
    cout << "-1\n";
    return 0;
}
