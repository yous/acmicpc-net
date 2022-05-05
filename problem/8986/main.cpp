#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> poles(N);
    for (int& num : poles) {
        cin >> num;
    }
    auto moves = [&](long long mid) {
        long long sum = 0;
        long long pos = 0;
        for (int num : poles) {
            sum += abs(pos - num);
            pos += mid;
        }
        return sum;
    };
    long long lo = 1;
    long long hi = 1e9;
    while (lo <= hi) {
        long long mid1 = lo + (hi - lo) / 3;
        long long mid2 = hi - (hi - lo) / 3;
        if (moves(mid1) >= moves(mid2)) {
            lo = mid1 + 1;
        } else {
            hi = mid2 - 1;
        }
    }
    cout << moves(hi) << "\n";
    return 0;
}
