#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

vector<int> preorder;
vector<tuple<int, int, int>> tree;

void postorder(int idx) {
    if (idx == -1) {
        return;
    }
    postorder(get<1>(tree[idx]));
    postorder(get<2>(tree[idx]));
    cout << preorder[idx] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;
    while (cin >> num) {
        preorder.push_back(num);
    }
    int sz = preorder.size();
    tree.resize(sz, {-1, -1, -1});
    num = preorder[0];
    for (int i = 1; i < sz; i++) {
        int next_num = preorder[i];
        if (next_num < num) {
            get<1>(tree[i - 1]) = i;
            get<0>(tree[i]) = i - 1;
        } else {
            int idx = i - 1;
            int parent_idx = get<0>(tree[idx]);
            while (parent_idx != -1 && preorder[parent_idx] < next_num) {
                idx = parent_idx;
                parent_idx = get<0>(tree[idx]);
            }
            int right_idx = get<2>(tree[idx]);
            while (right_idx != -1) {
                idx = right_idx;
                right_idx = get<2>(tree[idx]);
            }
            get<2>(tree[idx]) = i;
            get<0>(tree[i]) = idx;
        }
        num = next_num;
    }
    postorder(0);
    return 0;
}
