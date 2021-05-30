#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int N;
tuple<int, int, int> sizes[50];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int i, j;
    int x, y;
    for (i = 0; i < N; i++) {
        cin >> x >> y;
        sizes[i] = {x, y, 0};
    }
    for (i = 0; i < N; i++) {
        int& weight = get<0>(sizes[i]);
        int& height = get<1>(sizes[i]);
        int& rnk = get<2>(sizes[i]);
        rnk = 1;
        for (j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            if (weight < get<0>(sizes[j]) && height < get<1>(sizes[j])) {
                rnk += 1;
            }
        }
        cout << rnk;
        if (i < N - 1) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
