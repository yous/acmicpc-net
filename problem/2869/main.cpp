#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int A, B, V;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> A >> B >> V;
    int day = 1;
    int top = A;
    if (top >= V) {
        cout << day << "\n";
    } else {
        while (top < V) {
            day++;
            top += A - B;
        }
        cout << day << "\n";
    }
    return 0;
}
