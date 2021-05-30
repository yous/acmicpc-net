#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int num;
    int cur_top = 1;
    stack<int> st;
    vector<char> ops;
    bool pass = true;
    for (int i = 0; i < N; i++) {
        cin >> num;
        while (cur_top <= num) {
            ops.push_back('+');
            st.push(cur_top);
            cur_top++;
        }
        if (st.empty() || st.top() != num) {
            pass = false;
            cout << "NO\n";
            break;
        }
        ops.push_back('-');
        st.pop();
    }
    if (pass) {
        for (char op : ops) {
            cout << op << "\n";
        }
    }
    return 0;
}
