#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> players(N);
    vector<bool> is_player(1000001);
    for (auto& num : players) {
        cin >> num;
        is_player[num] = true;
    }
    vector<int> results(1000001);
    for (auto num : players) {
        for (int mul = num * 2; mul <= 1000000; mul += num) {
            if (is_player[mul]) {
                results[mul]--;
                results[num]++;
            }
        }
    }
    cout << results[players[0]];
    for (int i = 1; i < N; i++) {
        cout << " " << results[players[i]];
    }
    cout << "\n";
    return 0;
}
