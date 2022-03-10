#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int& num : A) {
        cin >> num;
    }
    int X;
    cin >> X;
    long long sum = 0;
    int cnt = 0;
    for (int num : A) {
        if (gcd(num, X) == 1) {
            sum += num;
            cnt++;
        }
    }
    cout.precision(7);
    cout << fixed << double(sum) / cnt << "\n";
    return 0;
}
