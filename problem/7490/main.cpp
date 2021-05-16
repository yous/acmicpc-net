#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
const int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const char ops[3] = {' ', '+', '-'};

void solve(char *results, int N, int index) {
    int sum = 0;
    int num = nums[0];
    bool add = true;
    if (index == N - 1) {
        for (int i = 0; i < N - 1; i++) {
            switch (results[i]) {
                case ' ':
                    num = num * 10 + nums[i + 1];
                    break;
                case '+':
                    sum += add ? num : -num;
                    num = nums[i + 1];
                    add = true;
                    break;
                case '-':
                    sum += add ? num : -num;
                    num = nums[i + 1];
                    add = false;
                    break;
            }
        }
        sum += add ? num : -num;
        if (sum == 0) {
            cout << nums[0];
            for (int i = 0; i < N - 1; i++) {
                cout << results[i] << nums[i + 1];
            }
            cout << "\n";
        }
        return;
    }
    for (char op : ops) {
        results[index] = op;
        solve(results, N, index + 1);
    }
}

int main() {
    cin >> T;
    while (T-- > 0) {
        int N;
        cin >> N;
        char results[N];
        for (int i = 0; i < N; i++) {
            results[i] = ' ';
        }
        solve(results, N, 0);
        if (T > 0) {
            cout << "\n";
        }
    }
    return 0;
}
