#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> sums;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    int num;
    int sum = 0;
    sums.push_back(sum);
    for (int i = 0; i < N; i++) {
        cin >> num;
        sum += num;
        sums.push_back(sum);
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << sums[b] - sums[a - 1] << "\n";
    }
    return 0;
}
