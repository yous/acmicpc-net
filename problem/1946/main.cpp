#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T;
int N;
int ranks[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        int count;
        int rank1, rank2;
        for (int i = 0; i < N; i++) {
            cin >> rank1 >> rank2;
            ranks[rank1] = rank2;
        }
        rank2 = ranks[1];
        count = 1;
        for (int i = 2; i <= N; i++) {
            if (ranks[i] < rank2) {
                count++;
                rank2 = ranks[i];
            }
        }
        cout << count << "\n";
    }
    return 0;
}
