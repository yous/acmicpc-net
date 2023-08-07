#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<bool> check(10);
    for (int i = 0; i < 5; i++) {
        int num;
        cin >> num;
        check[num] = !check[num];
    }
    for (int i = 0; i < 10; i++) {
        if (check[i]) {
            cout << i << "\n";
        }
    }
    return 0;
}
