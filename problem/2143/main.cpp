#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T, N, M;
vector<int> A_prefix;
vector<int> B_prefix;
vector<int> A_possible;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T >> N;
    int sum = 0;
    A_prefix.push_back(sum);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        sum += num;
        A_prefix.push_back(sum);
    }
    for (int lo = 0; lo <= N - 1; lo++) {
        for (int hi = lo + 1; hi <= N; hi++) {
            A_possible.push_back(A_prefix[hi] - A_prefix[lo]);
        }
    }
    sort(A_possible.begin(), A_possible.end());
    cin >> M;
    sum = 0;
    B_prefix.push_back(sum);
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        sum += num;
        B_prefix.push_back(sum);
    }
    long long cnt = 0;
    for (int lo = 0; lo <= M - 1; lo++) {
        for (int hi = lo + 1; hi <= M; hi++) {
            int to_find = T - (B_prefix[hi] - B_prefix[lo]);
            cnt += upper_bound(A_possible.begin(), A_possible.end(), to_find) -
                lower_bound(A_possible.begin(), A_possible.end(), to_find);
        }
    }
    cout << cnt << "\n";
    return 0;
}
