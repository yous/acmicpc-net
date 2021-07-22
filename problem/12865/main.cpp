#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> cache;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    cache.resize(K + 1);
    for (int i = 0; i < N; i++) {
        int w;
        short v;
        cin >> w >> v;
        for (int remain = K; remain >= w; remain--) {
            if (cache[remain - w] + v > cache[remain]) {
                cache[remain] = cache[remain - w] + v;
            }
        }
    }
    cout << cache[K] << "\n";
    return 0;
}
