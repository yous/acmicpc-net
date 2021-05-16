#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M;
int nums[20000001];

int main() {
    scanf("%d", &N);
    int num;
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        nums[num + 10000000] += 1;
    }
    scanf("%d", &M);
    for (int i = 0; i < M - 1; i++) {
        scanf("%d", &num);
        printf("%d ", nums[num + 10000000]);
    }
    scanf("%d", &num);
    printf("%d\n", nums[num + 10000000]);
    return 0;
}
