#include <stdio.h>

int arr[1001] = {0};

int dp(int n) {
    if (arr[n] != 0) return arr[n];
    // printf("계산: %d\n", n);
    int next = n / 2;
    int sum = 1;
    for (int i = 1; i <= next; i++) {
        sum += dp(i);
    }
    arr[n] = sum;
    // printf("계산 완료: %d\n", n);
    return arr[n];
}
int main() {
    int T; scanf("%d", &T);
    arr[1] = 1, arr[2] = 2, arr[3] = 2;
    for (int i = 0; i < T; i++) {
        int n, ans; scanf("%d", &n);
        ans = dp(n);
        printf("%d\n", ans);
    }
}