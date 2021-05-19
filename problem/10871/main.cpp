#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, X;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> X;
    int num;
    bool printed = false;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num < X) {
            if (!printed) {
                printed = true;
            } else {
                cout << " ";
            }
            cout << num;
        }
    }
    cout << "\n";
    return 0;
}
