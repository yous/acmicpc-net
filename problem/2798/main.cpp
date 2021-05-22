#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> cards;
int result;

void solve(int index, int count, int sum) {
    if (sum > M) {
        return;
    }
    if (count == 0) {
        if (sum > result) {
            result = sum;
        }
        return;
    }
    if (index == N) {
        return;
    }
    solve(index + 1, count, sum);
    solve(index + 1, count - 1, sum + cards[index]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    int i;
    int card;
    for (i = 0; i < N; i++) {
        cin >> card;
        cards.push_back(card);
    }
    solve(0, 3, 0);
    cout << result << "\n";
    return 0;
}
