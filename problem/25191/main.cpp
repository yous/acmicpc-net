#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    short A, B;
    cin >> A >> B;
    cout << min(N, short(A / 2 + B)) << "\n";
    return 0;
}
