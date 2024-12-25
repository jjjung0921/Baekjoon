#include <iostream>
#include <queue>
using namespace std;
int n, k, v[2][100000] = {1};
char a[2][100001];

int main() {
    scanf("%d %d %s %s", &n, &k, &a[0], &a[1]);
    queue<pair<int, int> > q; // <위치, 방향 왼0 오1>
    q.push({0, 0});
    while (!q.empty()) {
        int pos = q.front().first;
        int dir = q.front().second;
        q.pop();
        if (v[dir][pos] > pos + 1) continue;
        if (pos + k >= n) {
            printf("1");
            return 0;
        }
        if (a[dir][pos + 1] == '1' && !v[dir][pos + 1])
            v[dir][pos + 1] = v[dir][pos] + 1, q.push({pos + 1, dir});
        if (pos > 0 && a[dir][pos - 1] == '1' && !v[dir][pos - 1])
            v[dir][pos - 1] = v[dir][pos] + 1, q.push({pos - 1, dir});
        if (a[!dir][pos + k] == '1' && !v[!dir][pos + k])
            v[!dir][pos + k] = v[dir][pos] + 1, q.push({pos + k, !dir});
    }
    printf("0");
}
