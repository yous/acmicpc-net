#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> trees;

long long length_under(int limit) {
    long long sum = 0;
    for (auto it = trees.begin(); it != trees.end(); it++) {
        if (*it > limit) {
            sum += *it - limit;
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        trees.push_back(num);
    }
    int lo = 0;
    int hi = *max_element(trees.begin(), trees.end());
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (length_under(mid) < M) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo - 1 << "\n";
    return 0;
}
