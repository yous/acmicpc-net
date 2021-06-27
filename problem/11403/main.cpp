#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
bool graph[100][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (!graph[i][k]) {
                continue;
            }
            for (int j = 0; j < N; j++) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << (graph[i][0] ? "1" : "0");
        for (int j = 1; j < N; j++) {
            cout << " " << (graph[i][j] ? "1" : "0");
        }
        cout << "\n";
    }
    return 0;
}
