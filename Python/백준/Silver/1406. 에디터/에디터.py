import sys
from collections import deque

n = list(map(str, sys.stdin.readline().rstrip()))
m = int(sys.stdin.readline())

cursurBack = deque()
commend = []
for _ in range(m):
  commend.append(list(map(str, sys.stdin.readline().split())))

for i in commend:
  if i[0] == 'L':
    if len(n) >0:
      cursurBack.appendleft(n.pop())
  elif i[0] == 'D':
    if len(cursurBack)>0:
      n.append(cursurBack.popleft())
  elif i[0] == 'B':
    if len(n) >0:
      n.pop()
  else:
    n.append(i[1])
n.extend(cursurBack)
print(''.join(n))