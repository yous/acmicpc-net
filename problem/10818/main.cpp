#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int min = 1000000;
    int max = -1000000;
    int num;
    while (N-- > 0) {
        cin >> num;
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
    }
    cout << min << " " << max << "\n";
    return 0;
}
