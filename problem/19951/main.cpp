#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> grounds(N + 1);
    int prev_num = 0;
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        grounds[i] = num - prev_num;
        prev_num = num;
    }
    for (int i = 0; i < M; i++) {
        int a, b, k;
        cin >> a >> b >> k;
        grounds[a] += k;
        grounds[b + 1] -= k;
    }
    int num = grounds[0] + grounds[1];
    cout << num;
    for (int i = 2; i <= N; i++) {
        num += grounds[i];
        cout << " " << num;
    }
    cout << "\n";
    return 0;
}
