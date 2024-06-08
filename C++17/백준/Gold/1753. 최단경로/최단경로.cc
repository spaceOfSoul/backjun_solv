#include <iostream>
#include <queue>
#include <vector>
#define INF 9999999

std::vector<std::pair<int, int>> graph[20000]; // w, v pair
// w를 앞에 둠은 추후 우선순위 큐를 위함.
int distance_table[20000]; // 시작 정점 k로부터의 거리 저장

void djikstra(int start) {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
  que.push({0, start}); // dist, vertex
  distance_table[start] = 0;

  while (!que.empty()) {
    std::pair<int, int> current = que.top();
    
    int current_node = current.second;
    int current_dist = current.first;
    
    que.pop();


    if (distance_table[current_node] < current_dist)
      continue;

    for(auto pair : graph[current_node]){
      int next = pair.second;
      int next_dist = pair.first + current_dist;
      
      if(next_dist < distance_table[next]){
        distance_table[next] = next_dist;
        que.push({next_dist, next});
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int V, E;
  int k;
  int u, v, w;

  std::cin >> V >> E;
  std::cin >> k;

  for (int i = 0; i < V; i++) {
    distance_table[i] = INF;
  }

  while (E--) {
    std::cin >> u >> v >> w;
    graph[u - 1].push_back({w, v - 1});
  }

  djikstra(k-1);

  for(int i=0; i<V; i++){
    if(distance_table[i] == INF)
      std::cout << "INF\n";
    else
      std::cout << distance_table[i] << "\n";
  }
}