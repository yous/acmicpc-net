#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> inorder;
vector<int> postorder;
vector<int> rev_idx;

void preorder(int root, int inorder_lo, int inorder_hi, int postorder_lo, int postorder_hi) {
    if (inorder_lo == inorder_hi) {
        return;
    }
    int inorder_root = rev_idx[root];
    int postorder_left_idx = postorder_lo + inorder_root - inorder_lo - 1;
    int left_child = postorder[postorder_left_idx];
    if (inorder_lo <= inorder_root - 1 && postorder_lo <= postorder_left_idx) {
        cout << " " << left_child;
        preorder(left_child, inorder_lo, inorder_root - 1, postorder_lo, postorder_left_idx);
    }
    int postorder_right_idx = postorder_left_idx + inorder_hi - inorder_root;
    int right_child = postorder[postorder_right_idx];
    if (inorder_root + 1 <= inorder_hi && postorder_left_idx + 1 <= postorder_right_idx) {
        cout << " " << right_child;
        preorder(right_child, inorder_root + 1, inorder_hi, postorder_left_idx + 1, postorder_right_idx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    rev_idx.resize(N + 1);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        inorder.push_back(num);
        rev_idx[num] = i;
    }
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        postorder.push_back(num);
    }
    int root = postorder[N - 1];
    cout << root;
    preorder(root, 0, N - 1, 0, N - 1);
    cout << "\n";
    return 0;
}
