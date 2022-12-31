#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<short> mountains(N);
    for (auto& num : mountains) {
        cin >> num;
    }
    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        int width = mountains[i] + mountains[i + 1];
        int height = abs(mountains[i + 1] - mountains[i]);
        ans += width * width + height * height;
    }
    cout << ans << "\n";
    return 0;
}
