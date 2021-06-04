#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<short> times;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    short time;
    for (int i = 0; i < N; i++) {
        cin >> time;
        times.push_back(time);
    }
    sort(times.begin(), times.end());
    int sum = 0;
    int offset = 0;
    for (int i = 0; i < N; i++) {
        sum += offset + times[i];
        offset += times[i];
    }
    cout << sum << "\n";
    return 0;
}
