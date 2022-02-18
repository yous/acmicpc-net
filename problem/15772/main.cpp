#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short r1, r2, r3, r4;
    cin >> r1 >> r2 >> r3 >> r4;
    short f1, f2, f3, f4;
    cin >> f1 >> f2 >> f3 >> f4;
    int N;
    cin >> N;
    map<string, pair<int, short>> ma;
    for (int i = 0; i < N; i++) {
        short A;
        string B;
        cin >> A >> B;
        if (A == 1) {
            auto it = ma.find(B);
            if (it != ma.end()) {
                it->second.first = i + 1;
                it->second.second++;
            } else {
                ma.emplace_hint(it, B, make_pair(i + 1, 1));
            }
        } else {
            auto it = ma.find(B);
            if (it != ma.end()) {
                auto [r, f] = it->second;
                r = i + 1 - r;
                if (r <= r1) {
                    if (f <= f1) {
                        cout << "New Customer\n";
                    } else if (f <= f3) {
                        cout << "Potential Loyalist\n";
                    } else if (f <= f4) {
                        cout << "Loyal Customer\n";
                    } else {
                        cout << "Champion\n";
                    }
                } else if (r <= r2) {
                    if (f <= f1) {
                        cout << "Promising\n";
                    } else if (f <= f3) {
                        cout << "Potential Loyalist\n";
                    } else {
                        cout << "Loyal Customer\n";
                    }
                } else if (r <= r3) {
                    if (f <= f2) {
                        cout << "About to Sleep\n";
                    } else if (f <= f3) {
                        cout << "Need Attention\n";
                    } else {
                        cout << "Loyal Customer\n";
                    }
                } else if (r <= r4) {
                    if (f <= f1) {
                        cout << "Lost\n";
                    } else if (f <= f2) {
                        cout << "Hibernating\n";
                    } else {
                        cout << "About to Leave\n";
                    }
                } else {
                    if (f <= f2) {
                        cout << "Lost\n";
                    } else if (f <= f4) {
                        cout << "About to Leave\n";
                    } else {
                        cout << "Can't Lose Them\n";
                    }
                }
            } else {
                cout << "None\n";
            }
        }
    }
    return 0;
}
