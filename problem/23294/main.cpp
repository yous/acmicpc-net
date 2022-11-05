#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, Q;
    int C;
    cin >> N >> Q >> C;
    vector<int> CAP(N);
    for (auto& num : CAP) {
        cin >> num;
    }
    deque<int> backward_dq;
    int backward_cache = 0;
    deque<int> forward_dq;
    int cur_page = -1;
    for (int i = 0; i < Q; i++) {
        char cmd;
        cin >> cmd;
        switch (cmd) {
            case 'B':
                if (!backward_dq.empty()) {
                    forward_dq.emplace_back(cur_page);
                    int next_page = backward_dq.back();
                    backward_dq.pop_back();
                    backward_cache -= CAP[next_page];
                    cur_page = next_page;
                }
                break;
            case 'F':
                if (!forward_dq.empty()) {
                    backward_dq.emplace_back(cur_page);
                    backward_cache += CAP[cur_page];
                    int next_page = forward_dq.back();
                    forward_dq.pop_back();
                    cur_page = next_page;
                }
                break;
            case 'A':
                int page;
                cin >> page;
                page--;
                if (cur_page != -1) {
                    forward_dq.clear();
                    backward_dq.emplace_back(cur_page);
                    backward_cache += CAP[cur_page];
                    while (backward_cache + CAP[page] > C) {
                        int old_page = backward_dq.front();
                        backward_dq.pop_front();
                        backward_cache -= CAP[old_page];
                    }
                }
                cur_page = page;
                break;
            case 'C':
                if (!backward_dq.empty()) {
                    deque<int> compressed;
                    int prev_page = backward_dq.front();
                    backward_dq.pop_front();
                    compressed.emplace_back(prev_page);
                    while (!backward_dq.empty()) {
                        int page = backward_dq.front();
                        backward_dq.pop_front();
                        if (page == prev_page) {
                            backward_cache -= CAP[page];
                        } else {
                            compressed.emplace_back(page);
                            prev_page = page;
                        }
                    }
                    swap(backward_dq, compressed);
                }
                break;
        }
    }
    cout << cur_page + 1 << "\n";
    if (backward_dq.empty()) {
        cout << "-1\n";
    } else {
        int page = backward_dq.back();
        backward_dq.pop_back();
        cout << page + 1;
        while (!backward_dq.empty()) {
            page = backward_dq.back();
            backward_dq.pop_back();
            cout << " " << page + 1;
        }
        cout << "\n";
    }
    if (forward_dq.empty()) {
        cout << "-1\n";
    } else {
        int page = forward_dq.back();
        forward_dq.pop_back();
        cout << page + 1;
        while (!forward_dq.empty()) {
            page = forward_dq.back();
            forward_dq.pop_back();
            cout << " " << page + 1;
        }
        cout << "\n";
    }
    return 0;
}
