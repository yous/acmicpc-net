#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> preorder;
vector<pair<int, int>> tree;

void find_child(int root, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    int right_idx = lower_bound(preorder.begin() + lo, preorder.begin() + hi, preorder[root]) - preorder.begin();
    if (right_idx == lo) {
        tree[root].second = right_idx;
        find_child(right_idx, right_idx + 1, hi);
    } else if (right_idx < hi) {
        tree[root].first = lo;
        tree[root].second = right_idx;
        find_child(lo, lo + 1, right_idx);
        find_child(right_idx, right_idx + 1, hi);
    } else {
        tree[root].first = lo;
        find_child(lo, lo + 1, hi);
    }
}

void postorder(int idx) {
    if (idx == -1) {
        return;
    }
    postorder(tree[idx].first);
    postorder(tree[idx].second);
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
    tree.resize(sz, {-1, -1});
    find_child(0, 1, sz);
    postorder(0);
    return 0;
}
