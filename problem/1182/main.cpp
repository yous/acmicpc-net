#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int S;
int nums[20];
int results = 0;

void solve(int index, int count, int sum) {
    if (index >= N) {
        if (count != 0 && sum == S) {
            results++;
        }
        return;
    }
    solve(index + 1, count, sum);
    solve(index + 1, count + 1, sum + nums[index]);
}

int main() {
    int i;
    cin >> N >> S;
    for (i = 0; i < N; i++) {
        cin >> nums[i];
    }
    solve(0, 0, 0);
    cout << results << "\n";
    return 0;
}
