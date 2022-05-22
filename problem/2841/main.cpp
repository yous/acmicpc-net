#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, P;
    cin >> N >> P;
    vector<stack<int>> lines(6);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        short line;
        int fret;
        cin >> line >> fret;
        auto& st = lines[line - 1];
        if (st.empty()) {
            st.emplace(fret);
            ans++;
        } else {
            while (!st.empty() && st.top() > fret) {
                st.pop();
                ans++;
            }
            if (st.empty()) {
                st.emplace(fret);
                ans++;
            } else if (st.top() < fret) {
                st.emplace(fret);
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
