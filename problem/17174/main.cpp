#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    int sum = 0;
    int num = N;
    while (num > 0) {
        sum += num;
        num /= M;
    }
    cout << sum << "\n";
    return 0;
}
