#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    if (N == 1) {
        cout << "1\n";
        return 0;
    }
    int jump = N / 2;
    bool first = true;
    for (int i = jump; i >= 1; i--) {
        int n = i;
        while (n <= N) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << n;
            n += jump;
        }
    }
    cout << "\n";
    return 0;
}
