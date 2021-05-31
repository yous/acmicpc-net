#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, M;
map<string, string> PASS;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    string mail, pass;
    while (N-- > 0) {
        cin >> mail >> pass;
        PASS[mail] = pass;
    }
    while (M-- > 0) {
        cin >> mail;
        cout << PASS[mail] << "\n";
    }
    return 0;
}
