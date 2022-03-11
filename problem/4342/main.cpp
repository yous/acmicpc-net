#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B;
    while (cin >> A >> B) {
        if (A == 0 && B == 0) {
            break;
        }
        if (A < B) {
            swap(A, B);
        }
        bool A_wins = true;
        while (B > 0) {
            int num = A / B;
            A %= B;
            if (A == 0) {
                cout << (A_wins ? "A wins\n" : "B wins\n");
                break;
            } else {
                if (num >= 2) {
                    cout << (A_wins ? "A wins\n" : "B wins\n");
                    break;
                } else {
                    A_wins = !A_wins;
                }
            }
            swap(A, B);
        }
    }
    return 0;
}
