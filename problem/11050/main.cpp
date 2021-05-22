#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    int combi = 1;
    int num = N;
    for (int i = 0; i < K; i++) {
        combi *= num;
        num--;
    }
    for (int i = 1; i <= K; i++) {
        combi /= i;
    }
    cout << combi << "\n";
    return 0;
}
