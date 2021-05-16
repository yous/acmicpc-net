#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int max = 0;
    int score;
    double sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> score;
        sum += score;
        if (score > max) {
            max = score;
        }
    }
    cout << sum * 100 / max / N << "\n";
    return 0;
}
