#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;
string P;
int N;
vector<short> nums;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> P;
        cin >> N;
        nums.clear();
        nums.resize(N);
        char left_br, comma, right_br;
        cin >> left_br;
        if (N > 0) {
            cin >> nums[0];
        }
        for (int i = 1; i < N; i++) {
            cin >> comma >> nums[i];
        }
        cin >> right_br;
        int lo = 0;
        int hi = N - 1;
        bool right_order = true;
        bool is_error = false;
        for (auto ch : P) {
            if (ch == 'R') {
                right_order = !right_order;
            } else if (ch == 'D') {
                if (lo > hi) {
                    is_error = true;
                    break;
                }
                if (right_order) {
                    lo++;
                } else {
                    hi--;
                }
            }
        }
        if (is_error) {
            cout << "error\n";
        } else {
            if (right_order) {
                cout << "[";
                if (lo <= hi) {
                    cout << nums[lo];
                }
                for (int i = lo + 1; i <= hi; i++) {
                    cout << "," << nums[i];
                }
                cout << "]\n";
            } else {
                cout << "[";
                if (lo <= hi) {
                    cout << nums[hi];
                }
                for (int i = hi - 1; i >= lo; i--) {
                    cout << "," << nums[i];
                }
                cout << "]\n";
            }
        }
    }
    return 0;
}
