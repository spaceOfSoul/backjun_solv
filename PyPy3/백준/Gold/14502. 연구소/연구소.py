import sys
from collections import deque
import copy
input = sys.stdin.readline

n, m = map(int, input().split())

laboMap = []
virus = []
for i in range(n):
  laboMap.append(list(map(int, input().split())))
  for j in range(m):
    if laboMap[i][j] == 2:
      virus.append((i,j))
result = []
grp = []

def infection(r,c):
  que = deque()
  que.append((r,c))

  dx = [1,-1,0,0]
  dy = [0,0,1,-1]

  while que:
    x,y = que.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]

      if 0<= nx < n and 0 <= ny < m and grp[nx][ny] == 0:
        grp[nx][ny] = 2
        que.append((nx,ny))

def buildWall(cnt):
  global result
  global grp
  if cnt == 3:
    grp = copy.deepcopy(laboMap)
    for i in virus:
      infection(i[0],i[1])
    
    safeCount = 0
    for i in range(n):
      for j in range(m):
        if grp[i][j] == 0:
          safeCount +=1
    result.append(safeCount)
    return

  for i in range(n):
    for j in range(m):
      if laboMap[i][j] == 0:
        laboMap[i][j] = 1
        cnt += 1
        buildWall(cnt)
        laboMap[i][j] = 0
        cnt -= 1

buildWall(0)
print(max(result))