#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short K, H;
    int Q;
    cin >> K >> H >> Q;
    long long max_num = 1;
    for (int i = 0; i < H; i++) {
        max_num *= K + 1;
    }
    max_num--;
    for (int q = 0; q < Q; q++) {
        long long A, B;
        cin >> A >> B;
        if (A > max_num || B > max_num) {
            cout << "-1\n";
            continue;
        }
        if (A == B) {
            cout << "0\n";
            continue;
        }
        long long A_subtree = K + 1;
        short A_depth = H;
        while (A % A_subtree == 0) {
            A_depth--;
            A_subtree *= K + 1;
        }
        long long A_parent = A_subtree * (A / A_subtree + 1);
        long long B_subtree = K + 1;
        short B_depth = H;
        while (B % B_subtree == 0) {
            B_depth--;
            B_subtree *= K + 1;
        }
        long long B_parent = B_subtree * (B / B_subtree + 1);
        short ans = 2;
        while (A_depth > B_depth) {
            A_depth--;
            A_subtree *= K + 1;
            A_parent = A_subtree * (A / A_subtree + 1);
            ans++;
        }
        while (B_depth > A_depth) {
            B_depth--;
            B_subtree *= K + 1;
            B_parent = B_subtree * (B / B_subtree + 1);
            ans++;
        }
        while (A_parent != B_parent) {
            A_subtree *= K + 1;
            A_parent = A_subtree * (A / A_subtree + 1);
            B_subtree *= K + 1;
            B_parent = B_subtree * (B / B_subtree + 1);
            ans += 2;
        }
        cout << ans << "\n";
    }
    return 0;
}
