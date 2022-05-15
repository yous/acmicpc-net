#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N, M;
    cin >> N >> M;
    if ((N - 1) % (M + 1) != 0) {
        cout << "Can win\n";
    } else {
        cout << "Can't win\n";
    }
    return 0;
}
