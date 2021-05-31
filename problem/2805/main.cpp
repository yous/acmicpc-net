#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<long long> trees;

long long length_under(long long limit) {
    auto up_it = upper_bound(trees.begin(), trees.end(), limit);
    long long sum = 0;
    for (auto it = up_it; it != trees.end(); it++) {
        sum += *it - limit;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    long long num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        trees.push_back(num);
    }
    sort(trees.begin(), trees.end());
    long long lo = 0;
    long long hi = *prev(trees.end());
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (length_under(mid) < M) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo - 1 << "\n";
    return 0;
}
