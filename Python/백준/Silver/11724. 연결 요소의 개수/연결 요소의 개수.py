import sys
sys.setrecursionlimit(10**6)
n, m = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(n)]
visited = [False] * n
count = 0

for i in range(m):
  u, v = map(int, sys.stdin.readline().split())
  graph[u-1].append(v-1)
  graph[v-1].append(u-1)

def dfs(v):
  visited[v] = True
  for i in graph[v]:
    if not visited[i]:
      dfs(i)

for i in range(n):
  if not visited[i]:
    dfs(i)
    count += 1

print(count)