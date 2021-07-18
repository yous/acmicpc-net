#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void postorder(int root, int limit, int& num) {
    if (cin >> num) {
        if (num < root) {
            postorder(num, root, num);
        }
        if (num > root && num < limit) {
            postorder(num, limit, num);
        }
    }
    cout << root << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int root;
    cin >> root;
    int num;
    postorder(root, static_cast<int>(1e6), num);
    return 0;
}
