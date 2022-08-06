#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<short> weights(N);
    for (short& num : weights) {
        cin >> num;
    }
    vector<bool> visited(40501);
    vector<bool> prev_visited(40501);
    prev_visited[0] = true;
    for (short weight : weights) {
        for (int sum = 0; sum <= 40500; sum++) {
            if (prev_visited[sum]) {
                visited[sum] = true;
                if (sum + weight <= 40500) {
                    visited[sum + weight] = true;
                }
                visited[abs(sum - weight)] = true;
            }
        }
        swap(visited, prev_visited);
    }
    short T;
    cin >> T;
    T--;
    short num;
    cin >> num;
    cout << (prev_visited[num] ? "Y" : "N");
    while (T-- > 0) {
        cin >> num;
        cout << (prev_visited[num] ? " Y" : " N");
    }
    cout << "\n";
    return 0;
}
