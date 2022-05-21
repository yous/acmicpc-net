#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short K;
    int N;
    cin >> K >> N;
    vector<short> primes(K);
    set<int> sequence;
    for (short& num : primes) {
        cin >> num;
        sequence.emplace(num);
    }
    for (int i = 0; i < N - 1; i++) {
        for (short p : primes) {
            long long num = 1LL * *sequence.begin() * p;
            if (num >= (1LL << 31)) {
                break;
            }
            if (sequence.size() == N) {
                if (*sequence.rbegin() < num) {
                    break;
                }
                sequence.erase(prev(sequence.end()));
            }
            sequence.emplace(num);
        }
        sequence.erase(sequence.begin());
    }
    cout << *sequence.begin() << "\n";
    return 0;
}
