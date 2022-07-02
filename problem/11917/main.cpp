#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> S(N);
    vector<bool> visited(2000001);
    int uniq_cnt = 0;
    for (int& num : S) {
        cin >> num;
        if (!visited[num + 1000000]) {
            visited[num + 1000000] = true;
            uniq_cnt++;
        }
    }
    int M;
    cin >> M;
    int b_cnt = 1;
    while (uniq_cnt + b_cnt - 1 <= 1000000 && !visited[uniq_cnt + b_cnt - 1 + 1000000]) {
        b_cnt++;
    }
    if (uniq_cnt + b_cnt > 1000000) {
        b_cnt = 1e9;
    }
    if (M <= N) {
        cout << S[M - 1] << "\n";
    } else {
        if (M >= N + b_cnt) {
            cout << uniq_cnt + b_cnt - 1 << "\n";
        } else {
            cout << uniq_cnt + M - N - 1 << "\n";
        }
    }
    return 0;
}
