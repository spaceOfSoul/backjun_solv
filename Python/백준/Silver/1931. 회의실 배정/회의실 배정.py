import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
meetings = []
for i in range(n):
  a,b = map(int, input().split())
  meetings.append((b,a))
meetings.sort()

result = deque()
ptr=0
result.append(meetings[0])
for i in range(1,n):
  if meetings[i][1] >= result[ptr][0]:
    result.append(meetings[i])
    ptr += 1

print(ptr+1)