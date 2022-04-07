#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    if (N == 0) {
        cout << "0\n";
        return 0;
    }
    vector<short> scores(N);
    for (short& score : scores) {
        cin >> score;
    }
    sort(scores.begin(), scores.end());
    int cut = round(N * 0.15);
    int sum = 0;
    for (int i = cut; i < N - cut; i++) {
        sum += scores[i];
    }
    cout << round(1.0 * sum / (N - cut * 2)) << "\n";
    return 0;
}
