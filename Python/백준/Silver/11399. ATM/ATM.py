import sys

n = int(sys.stdin.readline())
p = list(map( int, sys.stdin.readline().split() ))

p.sort()
result = 0

for i in range(n +1):
  for k in range(i):
    result += p[k]

print(result)