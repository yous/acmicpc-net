#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int remain = N % 5;
    int total;
    switch (remain) {
        case 0:
            total = N / 5;
            break;
        case 1:
            if (N >= 5) {
                total = (N / 5 - 1) + 2;
            } else {
                total = -1;
            }
            break;
        case 2:
            if (N >= 10) {
                total = (N / 5 - 2) + 4;
            } else {
                total = -1;
            }
            break;
        case 3:
            total = N / 5 + 1;
            break;
        case 4:
            if (N >= 5) {
                total = (N / 5 - 1) + 3;
            } else {
                total = -1;
            }
            break;
    }
    cout << total << "\n";
    return 0;
}
