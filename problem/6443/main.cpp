#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
    cin >> N;
    while (N-- > 0) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());

        do {
            cout << s << "\n";
        } while (next_permutation(s.begin(), s.end()));
    }
    return 0;
}
