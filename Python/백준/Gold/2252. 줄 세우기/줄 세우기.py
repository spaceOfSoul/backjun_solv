import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())

compared = [[] for _ in range(n)]
indegree = [0] * n
result = []
for _ in range(m):
  a,b = map(int, input().split())
  compared[a-1].append(b-1)
  indegree[b-1] += 1

def trSort(r):
  que = deque()
  for i in range(n):
    if indegree[i] == 0:
      que.append(i)

  while que:
    now = que.popleft()
    r.append(now)

    for i in compared[now]:
      indegree[i] -= 1   
      if indegree[i] == 0:
        que.append(i)

trSort(result)
for i in result:
  print(i+1)