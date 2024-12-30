#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<int> edge[101];
int arr[101], dis[101], cnt=0;
bool add[101];

int BFS(int v, int n){
    queue<int> q; 
    cnt = 0; fill(add+1, add+n+1, false); fill(dis+1, dis+n+1, 0);
    q.push(v); add[v] = true;
    while(!q.empty()){
        int v = q.front(); q.pop();
        
        for(int to : edge[v]){
            if(!add[to]){
                q.push(to); add[to] = true;
                dis[to] = dis[v] + 1;
                cnt += dis[to];
            }
        }
    }
    return cnt;
}

int main(){
    int n, m; scanf("%d %d", &n, &m);
    for(int i=1; i<m+1; i++){
        int start, end; scanf("%d %d", &start, &end);
        edge[start].push_back(end); edge[end].push_back(start); //undirected graph
    }
    for(int i=1; i<n+1; i++){
        arr[i] = BFS(i, n);
    }
    int min_iter = *min_element(arr+1, arr+n+1);
    for(int i=1; i<n+1; i++){
        if(arr[i]==min_iter){
            printf("%d", i);
            return 0;
        }   
    }
}