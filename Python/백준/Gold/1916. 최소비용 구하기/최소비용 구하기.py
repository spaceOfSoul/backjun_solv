import sys
import heapq
input = sys.stdin.readline
inf = int(1e9)

n = int(input())
m = int(input())
grp = [[] for _ in range(n)]
distance = [inf] * n

for _ in range(m):
   s,d,c = map(int, input().split())
   grp[s-1].append((d-1,c))

start, finish = map(int, input().split())

def djs(v):
  que = []

  heapq.heappush(que, (0,v))
  distance[v] = 0
  while que:
    dist, now = heapq.heappop(que)
    if distance[now] < dist:
      continue
    for i in grp[now]:
      cost = dist + i[1]

      if cost < distance[i[0]]:
        distance[i[0]] = cost
        heapq.heappush(que, (cost, i[0]))
      
djs(start - 1)

print(distance[finish - 1])