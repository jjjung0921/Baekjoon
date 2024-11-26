#include <iostream>
#include <queue>
using namespace std;
int tomato[1001][1001], m, n; //m은 가로, n은 세로
//상하좌우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

queue<pair<int, int>> q; 

int bfs(){
    int x, y;
    while(!q.empty()){
        x = q.front().first; y = q.front().second;
        int nx, ny;
        for(int i=0; i<4; i++){
            nx = x + dx[i]; ny = y + dy[i];
            if(nx > -1 && nx < m && ny > -1 && ny < n){
                if(tomato[ny][nx] == 0){
                    tomato[ny][nx] = tomato[y][x]+1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        q.pop();
    }
    return tomato[y][x];
}

int search(){
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(tomato[i][j] == 0)
                return -1;
    return 1;
}

int main(){
    scanf("%d %d", &m, &n);
    //토마토 위치 입력
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &tomato[i][j]);
            
    //방문하지 않은 경우
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(tomato[i][j] == 1)
                q.push(make_pair(j, i)); //시작 지점 q에 입력
      
    //깊이우선탐색 수행
    int date = bfs();
    //0이 있는 지 확인
    printf("%d", search()==-1?search():date-1);
}