#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> clothes(N);
    for (int& num : clothes) {
        cin >> num;
    }
    if (N == 1 && clothes[0] == 1) {
        cout << "Happy\n";
        return 0;
    }
    sort(clothes.begin(), clothes.end());
    int max_num = clothes[N - 1];
    int others = 0;
    for (int i = 0; i < N - 1; i++) {
        others += clothes[i];
        if (others >= max_num) {
            cout << "Happy\n";
            return 0;
        }
    }
    cout << "Unhappy\n";
    return 0;
}
