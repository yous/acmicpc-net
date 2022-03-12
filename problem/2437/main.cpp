#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<int> weights(N);
    for (int& num : weights) {
        cin >> num;
    }
    sort(weights.begin(), weights.end());
    int prev_sum = weights[0];
    if (prev_sum > 1) {
        cout << "1\n";
        return 0;
    }
    bool found = false;
    for (int i = 1; i < N; i++) {
        if (prev_sum < weights[i] - 1) {
            found = true;
            cout << prev_sum + 1 << "\n";
            break;
        }
        prev_sum += weights[i];
    }
    if (!found) {
        cout << prev_sum + 1 << "\n";
    }
    return 0;
}
