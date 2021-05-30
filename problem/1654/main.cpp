#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector<int> lines;

int line_count(int unit) {
    int count = 0;
    for (int line : lines) {
        count += line / unit;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> K >> N;
    int i;
    for (i = 0; i < K; i++) {
        int line;
        cin >> line;
        lines.push_back(line);
    }
    unsigned int lo = 1;
    unsigned int hi = (1u << 31) - 1;
    while (lo <= hi) {
        unsigned int mid = (lo + hi) / 2;
        if (line_count(mid) < N) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo - 1 << "\n";
    return 0;
}
