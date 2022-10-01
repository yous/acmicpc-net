#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    int max_score = 0;
    for (int i = 0; i < N; i++) {
        short a, d, g;
        cin >> a >> d >> g;
        if (a == d + g) {
            max_score = max(max_score, a * (d + g) * 2);
        } else {
            max_score = max(max_score, a * (d + g));
        }
    }
    cout << max_score << "\n";
    return 0;
}
