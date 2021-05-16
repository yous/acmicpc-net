#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int nums[10001] = {0};

int main() {
    scanf("%d", &N);
    while (N-- > 0) {
        int num;
        scanf("%d", &num);
        nums[num] += 1;
    }
    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < nums[i]; j++) {
            printf("%d\n", i);
        }
    }
    return 0;
}
