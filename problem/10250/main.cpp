#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;
int H, W, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T-- > 0) {
        cin >> H >> W >> N;
        cout << ((N - 1) % H + 1) * 100 + (N - 1) / H + 1<< "\n";
    }
    return 0;
}
