#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    short Ac, D;
    cin >> Ac >> D;
    short Sr, Sc;
    cin >> Sr >> Sc;
    if (Sr >= 2 && Sr <= N - 1) {
        cout << "NO...\n";
    } else if (Sr == 1) {
        if ((D == 0 && Sc > Ac) || (D == 1 && Sc < Ac)) {
            cout << "YES!\n";
        } else {
            cout << "NO...\n";
        }
    } else {
        if ((D == 0 && N % 2 == 1) || (D == 1 && N % 2 == 0)) {
            cout << "YES!\n";
        } else {
            cout << "NO...\n";
        }
    }
    return 0;
}
