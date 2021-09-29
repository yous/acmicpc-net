#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
stack<pair<int, int>> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    long long ans = 0;
    int num;
    cin >> num;
    st.emplace(num, 1);
    for (int i = 1; i < N; i++) {
        cin >> num;
        int same_cnt = 0;
        if (!st.empty()) {
            auto [top, cnt] = st.top();
            while (top <= num) {
                ans += cnt;
                if (top == num) {
                    same_cnt = cnt;
                }
                st.pop();
                if (st.empty()) {
                    break;
                }
                auto& p = st.top();
                top = p.first;
                cnt = p.second;
            }
            if (!st.empty()) {
                ans++;
            }
        }
        st.emplace(num, same_cnt + 1);
    }
    cout << ans << "\n";
    return 0;
}
