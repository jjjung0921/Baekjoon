#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 21

int student[401][4];
int map[MAX_N][MAX_N];
int N;
int dx[] = {0, 0, 1, -1}; // 행
int dy[] = {1, -1, 0, 0}; // 열

typedef struct { // 위치와 빈칸, 매칭되는 사람 수
  int x;
  int y;
  int empty;
  int match;
} Info;

int compare(const void *a, const void *b) { // qsort를 위한 함수
  Info *infoA = (Info *)a;
  Info *infoB = (Info *)b;

  // 매칭 -> 빈칸 -> 행 -> 열 순으로 비교
  if (infoA->match == infoB->match) {
    if (infoA->empty == infoB->empty) {
      if (infoA->x == infoB->x)
        return infoA->y - infoB->y;
      return infoA->x - infoB->x;
    }
    return infoB->empty - infoA->empty;
  }
  return infoB->match - infoA->match;
}

// key: 자리에 앉는 학생 번호, x: 행, y: 열
Info bfs(int key, int x, int y) { // 너비탐색
  Info tmp = {x, y, 0, 0};        // 행,열,빈칸,매칭된 사람 수
  for (int i = 0; i < 4; i++) {   // 위, 아래, 우, 좌
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 1 || ny < 1 || nx > N || ny > N)
      continue;
    if (map[nx][ny] == 0) { // 비어있는 칸이라면
      tmp.empty++;          // 늘리고
      continue;             // 다음 좌석 확인
    }
    for (int j = 0; j < 4; j++) { // 좋아하는 학생 수 확인
      if (student[key][j] == map[nx][ny])
        tmp.match++;
    }
  }
  return tmp;
}

// key 학생 자리 선정 프로세스 시작
void matching(int key) {
  Info list[MAX_N * MAX_N]; // 자리 정보를 담을 배열
  int listSize = 0;

  for (int i = 1; i <= N; i++) { // map 1,1에서부터 탐색 시작
    for (int j = 1; j <= N; j++) {
      if (map[i][j] == 0) //비어있다면
        list[listSize++] = bfs(key, i, j); //자리에 앉을 학생 정보 저장
    }
  }

  qsort(list, listSize, sizeof(Info), compare);
  map[list[0].x][list[0].y] = key; // 최우선 자리에 앉힘
}

int getScore() {
  int sum = 0;
  for (int k = 1; k <= N * N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (map[i][j] == k) {
          Info tmp = bfs(k, i, j);
          if (tmp.match > 0) {
            sum += (int)pow(10, tmp.match - 1);
          }
          break;
        }
      }
    }
  }
  return sum;
}

int main() {
  scanf("%d", &N);
  int order[N * N]; // 학생 순서대로 입력

  for (int i = 0; i < N * N; i++) {
    int key;
    scanf("%d", &key); // 학생 번호 입력
    order[i] = key;
    for (int j = 0; j < 4; j++)
      scanf("%d", &student[key][j]); // 좋아하는 학생 입력
  }

  // 순서대로 자리에 착석
  for (int i = 0; i < N * N; i++)
    matching(order[i]);

  printf("%d\n", getScore());
  return 0;
}
