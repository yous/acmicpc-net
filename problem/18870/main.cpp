#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> points;
vector<int> ranks;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        points.push_back(num);
        ranks.push_back(num);
    }
    sort(ranks.begin(), ranks.end());
    ranks.erase(unique(ranks.begin(), ranks.end()), ranks.end());
    cout << lower_bound(ranks.begin(), ranks.end(), points[0]) - ranks.begin();
    for (int i = 1; i < N; i++) {
        cout << " " << lower_bound(ranks.begin(), ranks.end(), points[i]) - ranks.begin();
    }
    cout << "\n";
    return 0;
}
