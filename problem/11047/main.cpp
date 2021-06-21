#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> coins;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        coins.push_back(num);
    }
    int cnt = 0;
    int remain = K;
    for (auto it = coins.rbegin(); it != coins.rend(); ++it) {
        int c = remain / *it;
        cnt += c;
        remain -= *it * c;
        if (remain == 0) {
            break;
        }
    }
    cout << cnt << "\n";
    return 0;
}
