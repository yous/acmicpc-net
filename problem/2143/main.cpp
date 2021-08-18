#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T, N, M;
vector<int> A_prefix;
vector<int> A_possible;
vector<int> B;

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
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        B.push_back(num);
    }
    long long cnt = 0;
    for (int lo = 0; lo < M; lo++) {
        sum = 0;
        for (int hi = lo; hi < M; hi++) {
            sum += B[hi];
            int to_find = T - sum;
            cnt += upper_bound(A_possible.begin(), A_possible.end(), to_find) -
                lower_bound(A_possible.begin(), A_possible.end(), to_find);
        }
    }
    cout << cnt << "\n";
    return 0;
}
