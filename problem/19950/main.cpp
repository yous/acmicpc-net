#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    short N;
    cin >> N;
    vector<short> sticks(N);
    short sum = 0;
    short max_len = 0;
    for (short& num : sticks) {
        cin >> num;
        sum += num;
        if (max_len < num) {
            max_len = num;
        }
    }
    short rem = sum - max_len;
    int dist_sq = (z2 - z1) * (z2 - z1) + (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);
    if (sum * sum < dist_sq) {
        cout << "NO\n";
        return 0;
    }
    if (max_len > rem && (max_len - rem) * (max_len - rem) > dist_sq) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}
