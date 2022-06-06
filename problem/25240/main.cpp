#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int U, F;
    cin >> U >> F;
    cin.ignore(1, '\n');
    map<string, vector<string>> user_groups;
    for (int i = 0; i < U; i++) {
        string line;
        getline(cin, line);
        stringstream sstream(line);
        string user;
        vector<string> groups;
        getline(sstream, user, ' ');
        string group;
        while (getline(sstream, group, ',')) {
            groups.emplace_back(group);
        }
        user_groups[user] = groups;
    }
    map<string, tuple<short, string, string>> file_perm;
    for (int i = 0; i < F; i++) {
        string filename;
        short perm;
        string owner;
        string group;
        cin >> filename >> perm >> owner >> group;
        file_perm[filename] = {perm, owner, group};
    }
    int Q;
    cin >> Q;
    while (Q-- > 0) {
        string user, filename;
        char op;
        cin >> user >> filename >> op;
        if (op == 'R') {
            op = 4;
        } else if (op == 'W') {
            op = 2;
        } else {
            op = 1;
        }
        auto& [perm, owner, group] = file_perm[filename];
        if (user == owner) {
            cout << (((perm / 100) & op) != 0 ? 1 : 0) << "\n";
        } else if (user == group) {
            cout << (((perm / 10 % 10) & op) != 0 ? 1 : 0) << "\n";
        } else {
            auto& groups = user_groups[user];
            bool found = false;
            for (auto& u_group : groups) {
                if (u_group == group) {
                    found = true;
                    cout << (((perm / 10 % 10) & op) != 0 ? 1 : 0) << "\n";
                    break;
                }
            }
            if (!found) {
                cout << (((perm % 10) & op) != 0 ? 1 : 0) << "\n";
            }
        }
    }
    return 0;
}
