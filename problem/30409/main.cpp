#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> poles(N);
    for (auto& num : poles) {
        cin >> num;
    }
    vector<long long> dist_left(N);
    vector<long long> dist_right(N);
    stack<pair<int, int>> st;
    for (int i = 0; i < N; i++) {
        while (!st.empty()) {
            auto [h, idx] = st.top();
            if (h < poles[i]) {
                st.pop();
            } else {
                dist_left[i] = dist_left[idx] + 1LL * (h - poles[i]) * (h - poles[i]) + 1LL * (i - idx) * (i - idx);
                break;
            }
        }
        st.emplace(poles[i], i);
    }
    while (!st.empty()) {
        st.pop();
    }
    for (int i = N - 1; i >= 0; i--) {
        while (!st.empty()) {
            auto [h, idx] = st.top();
            if (h < poles[i]) {
                st.pop();
            } else {
                dist_right[i] = dist_right[idx] + 1LL * (h - poles[i]) * (h - poles[i]) + 1LL * (idx - i) * (idx - i);
                break;
            }
        }
        st.emplace(poles[i], i);
    }
    while (!st.empty()) {
        st.pop();
    }
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int P;
        cin >> P;
        P--;
        cout << dist_left[P] + dist_right[P] << "\n";
    }
    return 0;
}
