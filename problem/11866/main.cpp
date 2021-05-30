#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
bool removed[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    int count = 0;
    int idx = N - 1;
    cout << "<";
    while (count < N) {
        int moved = 0;
        while (moved < K) {
            idx++;
            idx %= N;
            if (!removed[idx]) {
                moved++;
            }
        }
        removed[idx] = true;
        cout << idx + 1;
        if (count < N - 1) {
            cout << ", ";
        }
        count++;
    }
    cout << ">\n";
    return 0;
}
