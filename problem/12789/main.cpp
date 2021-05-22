#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int N;
queue<int> cur_qu;
stack<int> tmp_st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i;
    int num;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> num;
        cur_qu.push(num);
    }
    int cur_idx = 1;
    while (!cur_qu.empty()) {
        int top = cur_qu.front();
        if (top == cur_idx) {
            cur_qu.pop();
            cur_idx++;
            continue;
        }
        if (!tmp_st.empty()) {
            int tmptop = tmp_st.top();
            if (tmptop == cur_idx) {
                tmp_st.pop();
                cur_idx++;
                continue;
            }
        }
        cur_qu.pop();
        tmp_st.push(top);
    }
    while (!tmp_st.empty()) {
        int top = tmp_st.top();
        if (top == cur_idx) {
            tmp_st.pop();
            cur_idx++;
        } else {
            break;
        }
    }
    if (cur_qu.empty() && tmp_st.empty()) {
        cout << "Nice\n";
    } else {
        cout << "Sad\n";
    }
    return 0;
}
