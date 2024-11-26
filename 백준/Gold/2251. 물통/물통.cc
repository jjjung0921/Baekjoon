#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

bool check[201][201][201]; //방문 기록
vector<int> result;
int a, b, c;
queue<tuple<int, int, int>> map;

void bfs(int x, int y, int z){
    map.push(make_tuple(x, y, z));
    while(!map.empty()){
        x = get<0>(map.front());
        y = get<1>(map.front());
        z = get<2>(map.front());
        map.pop();
        if(check[x][y][z]) continue; //이미 방문했으면 탐색 종료
        
        check[x][y][z] = true;
        if(x == 0) result.push_back(z);
        
        map.push(make_tuple(x, y, z));
        //A에서 B로
        if(x + y > b) map.push(make_tuple(x + y - b, b, z));
        else map.push(make_tuple(0, x + y, z));
        //A에서 C로
        if(x + z > c) map.push(make_tuple(x + z - c, y, c));
        else map.push(make_tuple(0, y, x + z));
        //B에서 A로
        if(x + y > a) map.push(make_tuple(a, x + y - a, z));
        else map.push(make_tuple(x + y, 0, z));
        //B에서 C로
        if(y + z > c) map.push(make_tuple(x, y + z - c, c));
        else map.push(make_tuple(x, 0, y + z));
        //C에서 A로
        if(x + z > a) map.push(make_tuple(a, y, x + z - a));
        else map.push(make_tuple(x + z, y, 0));
        //C에서 B로
        if(y + z > b) map.push(make_tuple(x, b, y + z - b));
        else map.push(make_tuple(x, y + z, 0));
    }
}

int main(){
    scanf("%d %d %d", &a, &b, &c);
    bfs(0, 0, c);
    sort(result.begin(), result.end());
    for(int i=0; i<result.size(); i++)
        printf("%d ", result[i]);
}