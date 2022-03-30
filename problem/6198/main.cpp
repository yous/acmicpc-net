#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    stack<int> dec_buildings;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        if (dec_buildings.empty() || dec_buildings.top() > h) {
            dec_buildings.push(h);
        } else {
            while (!dec_buildings.empty() && dec_buildings.top() <= h) {
                dec_buildings.pop();
            }
            dec_buildings.push(h);
        }
        ans += dec_buildings.size() - 1;
    }
    cout << ans << "\n";
    return 0;
}
