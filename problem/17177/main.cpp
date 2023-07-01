#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short A, B, C;
    cin >> A >> B >> C;
    if (C < A) {
        swap(A, C);
    }
    if (C < B) {
        swap(B, C);
    }
    if (C == A || C == B) {
        cout << "-1\n";
        return 0;
    }
    int AB = A;
    int BC = C;
    int CD = B;
    int AC_sq = BC * BC - AB * AB;
    int BD_sq = BC * BC - CD * CD;
    int AC_BD = sqrt(AC_sq * BD_sq);
    if (AC_BD <= AB * CD) {
        cout << "-1\n";
        return 0;
    }
    int AD = (AC_BD - AB * CD) / BC;
    cout << AD << "\n";
    return 0;
}
