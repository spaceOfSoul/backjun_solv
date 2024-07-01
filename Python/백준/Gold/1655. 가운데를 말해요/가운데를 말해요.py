import sys
import heapq
input = sys.stdin.readline

n = int(input())
rq = []
lq =[]
result = []

for _ in range(n):
  num = int(input())
  if not lq:
    heapq.heappush(lq,-num)
    result.append(num)
    continue
  else:
    if -lq[0] >= num:
      heapq.heappush(lq,-num)
      if len(lq) > len(rq) +1:
        heapq.heappush(rq,-heapq.heappop(lq))
    else:
      heapq.heappush(rq,num)
      if len(rq) > len(lq):
        heapq.heappush(lq,-heapq.heappop(rq))
  result.append(-lq[0])

for i in result:
  print(i)