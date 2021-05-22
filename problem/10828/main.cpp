#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
stack<int> _stack;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    string cmd;
    int num;
    while (N-- > 0) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> num;
            _stack.push(num);
        } else if (cmd == "pop") {
            if (_stack.empty()) {
                cout << "-1\n";
            } else {
                cout << _stack.top() << "\n";
                _stack.pop();
            }
        } else if (cmd == "size") {
            cout << _stack.size() << "\n";
        } else if (cmd == "empty") {
            cout << (_stack.empty() ? 1 : 0) << "\n";
        } else {
            // "top"
            if (_stack.empty()) {
                cout << "-1\n";
            } else {
                cout << _stack.top() << "\n";
            }
        }
    }
    return 0;
}
