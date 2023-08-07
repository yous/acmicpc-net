#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(100001);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        A[num] = 1;
    }
    for (int i = 1; i <= 100000; i++) {
        if (!A[i]) {
            continue;
        }
        int num = i * 2;
        while (num <= 100000) {
            A[num] += A[i];
            num += i;
        }
    }
    int Q;
    cin >> Q;
    bool first = true;
    for (int i = 0; i < Q; i++) {
        int L;
        cin >> L;
        if (first) {
            first = false;
        } else {
            cout << " ";
        }
        cout << A[L];
    }
    cout << "\n";
    return 0;
}
