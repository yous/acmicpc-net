#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
queue<int> myqueue;

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
            myqueue.push(num);
        } else if (cmd == "pop") {
            if (myqueue.empty()) {
                cout << "-1\n";
            } else {
                cout << myqueue.front() << "\n";
                myqueue.pop();
            }
        } else if (cmd == "size") {
            cout << myqueue.size() << "\n";
        } else if (cmd == "empty") {
            cout << (myqueue.empty() ? 1 : 0) << "\n";
        } else if (cmd == "front") {
            if (myqueue.empty()) {
                cout << "-1\n";
            } else {
                cout << myqueue.front() << "\n";
            }
        } else {
            // "back"
            if (myqueue.empty()) {
                cout << "-1\n";
            } else {
                cout << myqueue.back() << "\n";
            }
        }
    }
    return 0;
}
