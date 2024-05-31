import sys

n, m = map(int, sys.stdin.readline().split())

graph = []
for _ in range(m):
  a,b,c = map(int, sys.stdin.readline().split())
  graph.append((a-1,b-1,c))

distance = [int(1e9)] * n
distance[0] = 0
isCycle = False

for i in range(n):
  for j in graph:
    now,nxt,cost = j[0],j[1],j[2]

    if distance[now] != int(1e9):
      if distance[nxt] > distance[now] + cost:
        distance[nxt] = distance[now] + cost

        if i == n-1:
          isCycle = True

if isCycle:
  print(-1)
else:
  for i in range(1,n):
    if distance[i] == int(1e9):
      print(-1)
    else:
      print(distance[i])