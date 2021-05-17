#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= 9; i++) {
        cout << N << " * " << i << " = " << N * i << "\n";
    }
    return 0;
}
