import sys

n = int(sys.stdin.readline())

p = [1,2,3,5]

if n >= 4:
  for i in range(4,n+1):
    p.append( (p[i-1] + p[i-2]) % 15746)

print(p[n-1])