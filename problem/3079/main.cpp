#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M;
long long times[100000];

bool check(long long time) {
    long long passed = 0;
    for (int i = 0; i < N; i++) {
        passed += time / times[i];
    }
    return passed >= M;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &times[i]);
    }
    long long l, r;
    l = 1;
    r = times[0] * M;
    while (l < r) {
        long long k = (l + r) / 2;
        if (!check(k)) {
            l = k + 1;
        } else {
            r = k;
        }
    }
    printf("%lld\n", l);
    return 0;
}
