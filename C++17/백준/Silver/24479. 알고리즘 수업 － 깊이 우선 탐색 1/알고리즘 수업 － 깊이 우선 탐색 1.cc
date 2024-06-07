#include <algorithm>
#include <iostream>
#include <vector>

int visited[100000];
std::vector<int> graph[100000];

int n, m, r;
int sequence = 1;

void dfs(int current) {
  visited[current] = sequence;
  sequence++;
  for (int i : graph[current]) {
    if (!visited[i])
      dfs(i);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int a, b;
  std::cin >> n >> m >> r;

  while (m--) {
    std::cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }
  for (int i = 0; i < n; i++) {
    std::sort(graph[i].begin(), graph[i].end());
  }

  dfs(r - 1);

  for (int i = 0; i < n; i++) {
    std::cout << visited[i] << "\n";
  }
}