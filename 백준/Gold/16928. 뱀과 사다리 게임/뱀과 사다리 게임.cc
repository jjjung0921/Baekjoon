#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

typedef struct {
    int now;
    int time;
} Box;

int w[100];

bool visit[100];

queue<Box> q;

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i=0; i<n+m; i++) {
        int start, end; scanf("%d %d", &start, &end);
        w[start-1] = end - start;
    }
    Box box; box.now = 0; box.time = 0;
    q.push(box); int result = 0;
    while (!q.empty()) {
        Box b = q.front();
        int now = b.now, time = b.time;
        //printf("%d %d\n", now, time);
        if (now == 99) {result = time; break;}
        for (int i=1; i<=6; i++) {
            Box n;
            if (visit[now + i] || now + i > 99) continue;
            if (w[now + i] == 0) {
                n.now = now + i; n.time = time + 1;
                visit[now + i] = true;
            } else {
                n.now = now + i + w[now + i]; n.time = time + 1;
                visit[now + i] = true; visit[n.now] = true;
            }
            q.push(n);
        }
        q.pop();
    }
    printf("%d", result);
}
