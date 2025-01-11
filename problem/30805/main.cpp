#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<short> A(N);
    for (auto& num : A) {
        cin >> num;
    }
    short M;
    cin >> M;
    vector<short> B(M);
    for (auto& num : B) {
        cin >> num;
    }
    vector<deque<short>> A_cnt(101);
    vector<deque<short>> B_cnt(101);
    for (int i = 0; i < N; i++) {
        A_cnt[A[i]].emplace_back(i);
    }
    for (int i = 0; i < M; i++) {
        B_cnt[B[i]].emplace_back(i);
    }
    vector<short> ans;
    int A_idx = 0;
    int B_idx = 0;
    while (true) {
        bool found = false;
        for (int i = 100; i >= 1; i--) {
            while (!A_cnt[i].empty() && A_cnt[i][0] < A_idx) {
                A_cnt[i].pop_front();
            }
            while (!B_cnt[i].empty() && B_cnt[i][0] < B_idx) {
                B_cnt[i].pop_front();
            }
            if (!A_cnt[i].empty() && !B_cnt[i].empty()) {
                found = true;
                ans.emplace_back(i);
                A_idx = A_cnt[i][0];
                A_cnt[i].pop_front();
                B_idx = B_cnt[i][0];
                B_cnt[i].pop_front();
                break;
            }
        }
        if (!found) {
            break;
        }
    }
    cout << ans.size() << "\n";
    if (!ans.empty()) {
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++) {
            cout << " " << ans[i];
        }
        cout << "\n";
    }
    return 0;
}
