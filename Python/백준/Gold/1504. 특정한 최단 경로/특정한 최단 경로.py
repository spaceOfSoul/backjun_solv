import sys
import heapq

n, e = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(n)]
for _ in range(e):
  a,b,c = map(int, sys.stdin.readline().split())
  graph[a-1].append((b-1,c))
  graph[b-1].append((a-1,c))

v1, v2 = map(int, sys.stdin.readline().split())

def djs(st):
  distance = [int(1e9)] * n
  que = []

  heapq.heappush(que,(0, st))
  distance[st] = 0
  
  while que:
    dist, now = heapq.heappop(que)

    if distance[now] < dist:
      continue
    for i in graph[now]:
      cost = dist + i[1]
      if cost < distance[i[0]]:
        distance[i[0]] = cost
        heapq.heappush(que,(cost, i[0]))
  
  return distance

fromS = djs(0)
fromV1 = djs(v1-1)
fromV2 = djs(v2 - 1)

case1 = fromS[v1-1] + fromV1[v2-1] + fromV2[n-1]
case2 = fromS[v2-1] + fromV2[v1-1] + fromV1[n-1]

if case1 >= int(1e9) and case2 >= int(1e9):
  print(-1)
else:
  print(min(case1, case2))