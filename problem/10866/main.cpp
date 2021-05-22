#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int N;
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    string cmd;
    int num;
    while (N-- > 0) {
        cin >> cmd;
        if (cmd == "push_front") {
            cin >> num;
            dq.push_front(num);
        } else if (cmd == "push_back") {
            cin >> num;
            dq.push_back(num);
        } else if (cmd == "pop_front") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        } else if (cmd == "pop_back") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        } else if (cmd == "size") {
            cout << dq.size() << "\n";
        } else if (cmd == "empty") {
            cout << (dq.empty() ? 1 : 0) << "\n";
        } else if (cmd == "front") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.front() << "\n";
            }
        } else if (cmd == "back") {
            if (dq.empty()) {
                cout << "-1\n";
            } else {
                cout << dq.back() << "\n";
            }
        }
    }
    return 0;
}
