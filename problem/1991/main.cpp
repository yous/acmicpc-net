#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
short tree[26][2];

void preorder(int idx) {
    if (idx == -1) {
        return;
    }
    cout << static_cast<char>('A' + idx);
    preorder(tree[idx][0]);
    preorder(tree[idx][1]);
}

void inorder(int idx) {
    if (idx == -1) {
        return;
    }
    inorder(tree[idx][0]);
    cout << static_cast<char>('A' + idx);
    inorder(tree[idx][1]);
}

void postorder(int idx) {
    if (idx == -1) {
        return;
    }
    postorder(tree[idx][0]);
    postorder(tree[idx][1]);
    cout << static_cast<char>('A' + idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        char p, a, b;
        cin >> p >> a >> b;
        tree[p - 'A'][0] = (a == '.' ? -1 : a - 'A');
        tree[p - 'A'][1] = (b == '.' ? -1 : b - 'A');
    }
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
    cout << "\n";
    return 0;
}
