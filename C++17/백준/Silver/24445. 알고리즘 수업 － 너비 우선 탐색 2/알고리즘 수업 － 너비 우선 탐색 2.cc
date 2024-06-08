#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int n, m, r;
int u, v;

int visited[100000];
std::vector<int> graph[100000];

void bfs(int r) {
  std::queue<int> que;

  int sequence = 1;
  int current;

  visited[r - 1] = sequence;
  que.push(r - 1);
  // std::cout << "visited\n";

  while (!que.empty()) {
    current = que.front();

    que.pop();

    for (int i : graph[current]) {
      if (!visited[i]) {
        visited[i] = ++sequence;
        que.push(i);
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::cin >> n >> m >> r;

  while (m--) {
    std::cin >> u >> v;
    graph[u - 1].push_back(v - 1);
    graph[v - 1].push_back(u - 1);
  }

  int i;

  for (i = 0; i < n; i++) {
    std::sort(graph[i].rbegin(), graph[i].rend());
  }

  bfs(r);

  for (i = 0; i < n; i++) {
    std::cout << visited[i] << "\n";
  }
}