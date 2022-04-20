#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int num;
    Node* prev;
    Node* next;

    Node(int num) : num(num), prev(this), next(this) {}
};

void insert(Node* node, Node* item) {
    item->next = node->next;
    item->prev = node;
    node->next->prev = item;
    node->next = item;
}

void erase(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<Node*> unique_map(1000001);
    int first_num;
    cin >> first_num;
    unique_map[first_num] = new Node(first_num);
    int prev_num = first_num;
    for (int i = 1; i < N; i++) {
        int num;
        cin >> num;
        unique_map[num] = new Node(num);
        unique_map[num]->prev = unique_map[prev_num];
        unique_map[prev_num]->next = unique_map[num];
        prev_num = num;
    }
    unique_map[prev_num]->next = unique_map[first_num];
    unique_map[first_num]->prev = unique_map[prev_num];
    for (int m = 0; m < M; m++) {
        char cmd1, cmd2;
        cin >> cmd1 >> cmd2;
        if (cmd1 == 'B') {
            int i, j;
            cin >> i >> j;
            if (cmd2 == 'N') {
                int i_next = unique_map[i]->next->num;
                cout << i_next << "\n";
                unique_map[j] = new Node(j);
                insert(unique_map[i], unique_map[j]);
            } else {
                int i_prev = unique_map[i]->prev->num;
                cout << i_prev << "\n";
                unique_map[j] = new Node(j);
                insert(unique_map[i]->prev, unique_map[j]);
            }
        } else {
            int i;
            cin >> i;
            if (cmd2 == 'N') {
                cout << unique_map[i]->next->num << "\n";
                erase(unique_map[i]->next);
            } else {
                cout << unique_map[i]->prev->num << "\n";
                erase(unique_map[i]->prev);
            }
        }
    }
    return 0;
}
