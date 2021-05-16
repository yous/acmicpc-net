#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int M;
vector<int> cards;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int num;
    while (N-- > 0) {
        cin >> num;
        cards.push_back(num);
    }
    sort(cards.begin(), cards.end());
    cin >> M;
    while (M-- > 0) {
        cin >> num;
        cout << upper_bound(cards.begin(), cards.end(), num) - lower_bound(cards.begin(), cards.end(), num);
        if (M > 0) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
