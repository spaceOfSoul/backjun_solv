#include <iostream>
#include <queue>
#define MAX 999999999
using namespace std;

int n, m, k;

char arr[1000][1000];
int visited[1000][1000][11];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

typedef struct triple {
  int first, second, third; // x,y,벽
} triple;

int bfs() {
  queue<triple> que;
  que.push({0, 0, 0});
  visited[0][0][0] = 1;

  while (!que.empty()) {
    int x = que.front().first;
    int y = que.front().second;
    int drill = que.front().third;
    que.pop();

    if (x == n - 1 && y == m - 1)
      return visited[x][y][drill];

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (0 <= nx && nx < n && 0 <= ny && ny < m) {
        if (arr[nx][ny] == '1') { // block
          if (drill >= k)
            continue;
          if (!visited[nx][ny][drill + 1]) {
            visited[nx][ny][drill + 1] = visited[x][y][drill] + 1;
            que.push({nx, ny, drill + 1});
          }
        } else { // open
          if (!visited[nx][ny][drill]) {
            visited[nx][ny][drill] = visited[x][y][drill] + 1;
            que.push({nx, ny, drill});
          }
        }
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];

  cout << bfs();
}