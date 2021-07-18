#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int A, B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> A >> B;
    int cnt = 1;
    while (B > A) {
        while (B % 2 == 0) {
            B /= 2;
            cnt++;
            if (B == A) {
                break;
            }
        }
        if (B == A) {
            break;
        }
        if (B % 10 != 1) {
            break;
        }
        B /= 10;
        cnt++;
    }
    if (B == A) {
        cout << cnt << "\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}
