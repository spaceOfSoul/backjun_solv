import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
stack = deque()
nn = []#is same?

for _ in range(n):
  nn.append(int(input()))
nnCopy = nn.copy()

result = []
yun = []
pointr = 0
size = len(nnCopy)
nn.sort()

for pointr in range(n):
  if not stack:
    stack.append(nn[0])
    yun.append('+')
    nn.remove(nn[0])
  if stack[len(stack) - 1] != nnCopy[pointr]:
    while nn and stack[len(stack) - 1] != nnCopy[pointr]:
      stack.append(nn[0])
      nn.remove(nn[0])
      yun.append('+')

  if stack[len(stack) - 1] == nnCopy[pointr]:
    result.append(stack.pop())
    yun.append('-')
    continue
  break

if result == nnCopy:
  for i in yun:
    print(i)
else:
  print('NO')