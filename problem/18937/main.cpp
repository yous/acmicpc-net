#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
string king;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        ans ^= (num - 2);
    }
    cin >> king;
    if (king[0] == 'W') {
        cout << (ans == 0 ? "Blackking\n" : "Whiteking\n");
    } else {
        cout << (ans == 0 ? "Whiteking\n" : "Blackking\n");
    }
    return 0;
}
