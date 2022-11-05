#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> rev_A(N);
    int rev_cnt = 0;
    for (auto& num : A) {
        cin >> num;
        num--;
        rev_A[num]++;
        rev_cnt++;
    }
    rev_A[A[0]]--;
    rev_cnt--;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < N; i++) {
        pq.emplace(-rev_A[i], i);
    }
    vector<int> ans;
    vector<bool> visited(N);
    int visited_cnt = 1;
    visited[0] = true;
    int cur_person = 0;
    while (rev_cnt > 0) {
        if (cur_person == -1) {
            auto [cnt, floor] = pq.top();
            cnt = -cnt;
            pq.pop();
            if (cnt > rev_A[floor]) {
                continue;
            }
            if (visited[floor]) {
                continue;
            }
            ans.emplace_back(floor);
            cur_person = floor;
            visited_cnt++;
            visited[cur_person] = true;
            rev_A[A[cur_person]]--;
            rev_cnt--;
            pq.emplace(-rev_A[A[cur_person]], A[cur_person]);
        }
        ans.emplace_back(A[cur_person]);
        int next_person = A[cur_person];
        if (visited[next_person]) {
            cur_person = -1;
        } else {
            visited_cnt++;
            visited[next_person] = true;
            cur_person = next_person;
            rev_A[A[cur_person]]--;
            rev_cnt--;
            pq.emplace(-rev_A[A[cur_person]], A[cur_person]);
        }
    }
    if (cur_person != -1) {
        ans.emplace_back(A[cur_person]);
    }
    cout << ans.size() << "\n";
    cout << ans[0] + 1;
    for (int i = 1; i < ans.size(); i++) {
        cout << " " << ans[i] + 1;
    }
    cout << "\n";
    return 0;
}
