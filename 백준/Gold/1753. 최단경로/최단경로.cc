#define INF 987654321

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
    int to;
    int weight;
};

vector<vector<Edge>> adj;

vector<int> dist;

void dijkstra(int start) {
    priority_queue<
        pair<int,int>, //value_type (거리, 정점)
        vector<pair<int,int>>, //내부 저장 구조?
        greater<pair<int,int>> //정렬 기준 (큰 거리부터 우선 넣기)
    > pq;

    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [cur_dist, u] = pq.top();
        pq.pop();

        if (cur_dist > dist[u]) continue;

        for (auto &e : adj[u]) {
            int v = e.to;
            int w = e.weight;

            int nd = cur_dist + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.emplace(nd, v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int v, e; scanf("%d %d", &v, &e);
    int start_node; scanf("%d", &start_node);

    dist = vector<int>(v + 1, INF);
    adj.resize(v + 1);

    for (int i=0; i<e; i++) {
        int start, end, distance; scanf("%d %d %d", &start, &end, &distance);
        // printf("Edge 초기화 시작\n");
        Edge edge = {end, distance};
        // printf("adj 크기: %d\n", adj.size());
        adj[start].push_back(edge);
    }

    dijkstra(start_node);

    for (int i = 1; i < v + 1; i++) {
        if (dist[i] != INF) printf("%d\n", dist[i]);
        else printf("INF\n");
    }
}