#include <iostream>
#include <string.h>
using namespace std;
int n, map[100][100], visit[100];

void recursive(int start) {
    for (int i = 0; i < n; i++) {
        if (map[start][i])
            if (!visit[i]) {
                visit[i] = 1;
                recursive(i);
            }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
    for (int i = 0; i < n; i++) {
        recursive(i);
        for (int j = 0; j < n; j++)
            printf("%d ", visit[j]);
        memset(visit, 0, sizeof(visit));
        printf("\n");
    }
}
