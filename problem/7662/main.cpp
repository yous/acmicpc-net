#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int T, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T-- > 0) {
        cin >> k;
        map<int, int> mymap;
        char cmd;
        int n;
        int i;
        for (i = 0; i < k; i++) {
            cin >> cmd >> n;
            switch (cmd) {
                case 'I': {
                    auto it = mymap.find(n);
                    if (it != mymap.end()) {
                        it->second++;
                    } else {
                        mymap[n] = 1;
                    }
                    break;
                }
                case 'D': {
                    if (!mymap.empty()) {
                        if (n == 1) {
                            auto it = prev(mymap.end());
                            if (it->second > 1) {
                                it->second--;
                            } else {
                                mymap.erase(it);
                            }
                        } else {
                            // -1
                            auto it = mymap.begin();
                            if (it->second > 1) {
                                it->second--;
                            } else {
                                mymap.erase(it);
                            }
                        }
                    }
                    break;
                }
            }
        }
        if (mymap.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << mymap.rbegin()->first << " " << mymap.begin()->first << "\n";
        }
    }
    return 0;
}
