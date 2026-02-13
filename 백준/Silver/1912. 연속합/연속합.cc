#define MIN -987654321
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    int* arr = (int*) malloc(sizeof(int)*n);

    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &arr[i]);
    }

    int max = MIN;

    for (int i = 0; i < n; i++) {
        max = (max < arr[i]) ? arr[i] : max;
    }

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            // printf("%d %d\n", i, j);
            if (sum > 0) max = (max < sum) ? sum : max;
            else break;
        }
    }
    printf("%d", max);
}
