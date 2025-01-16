#include <iostream>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;
int dx[6] = {-2, -2, 0, 0, 2, 2}; //이동 경로
int dy[6] = {-1, 1, -2, 2, -1, 1};
bool isVisit[200][200]; //방문 기록
int main() {
    int n; scanf("%d", &n); //체스판 크기
    tuple<int, int, int> start;
    int end_x, end_y;
    scanf("%d %d", &get<0>(start), &get<1>(start));
    scanf("%d %d", &end_x, &end_y);
    get<2>(start) = 0;
    queue<tuple<int, int, int>> q;
    q.push(start);
    while (!q.empty()) {
        tuple<int, int, int> front = q.front();
        q.pop(); //제거
        int x = get<0>(front), y = get<1>(front), level = get<2>(front);
        isVisit[x][y] = true; //방문 기록
        for (int i=0; i<6; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isVisit[nx][ny] || nx < 0 || nx >= n || ny < 0 || ny >=n) continue; //이미 방문했으면 건너뜀
            if (nx == end_x && ny == end_y) {printf("%d", level + 1); return 0;} //정답을 찾으면 종료
            q.push(make_tuple(nx, ny, level + 1));
            isVisit[nx][ny] = true;
        }
    }
    printf("-1"); //갈 수 없으면 -1
    return 0;
}