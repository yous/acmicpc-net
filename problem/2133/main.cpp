#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    if (N % 2 == 1) {
        cout << "0\n";
        return 0;
    }
    vector<int> cache(N / 2 + 1);
    cache[1] = 3;
    for (int i = 2; i <= N / 2; i++) {
        cache[i] = cache[i - 1] * 3;
        for (int j = i - 2; j >= 1; j--) {
            cache[i] += cache[j] * 2;
        }
        cache[i] += 2;
    }
    cout << cache[N / 2] << "\n";
    return 0;
}
