#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> s;
    int sum = 0;
    for (char c : s) {
        sum += c - '0';
    }
    cout << sum << "\n";
    return 0;
}
