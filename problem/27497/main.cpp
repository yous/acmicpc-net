#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<bool> cmds;
    deque<char> ans;
    for (int i = 0; i < N; i++) {
        short cmd;
        cin >> cmd;
        if (cmd == 1) {
            char ch;
            cin >> ch;
            cmds.emplace_back(true);
            ans.emplace_back(ch);
        } else if (cmd == 2) {
            char ch;
            cin >> ch;
            cmds.emplace_back(false);
            ans.emplace_front(ch);
        } else {
            if (!cmds.empty()) {
                bool is_back = cmds.back();
                if (is_back) {
                    ans.pop_back();
                } else {
                    ans.pop_front();
                }
                cmds.pop_back();
            }
        }
    }
    if (ans.empty()) {
        cout << "0\n";
    } else {
        for (char ch : ans) {
            cout << ch;
        }
        cout << "\n";
    }
    return 0;
}
