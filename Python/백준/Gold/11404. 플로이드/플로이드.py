import sys

input = sys.stdin.readline

n = int(input())
m = int(input())
graph = [[int(1e9)] * n for _ in range(n)]

for i in range(n):
      graph[i][i] = 0

for _ in range(m):
  a,b,c = map(int, input().split())
  graph[a-1][b-1] = min(graph[a-1][b-1],c)

for i in range(n):
  for j in range(n):
    for k in range(n):
      graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k])

for i in graph:
  for j in i:
    if j == int(1e9):
      print(0, end = ' ')
    else:
      print(j, end = ' ')

  print()