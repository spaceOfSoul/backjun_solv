import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

v,e = map(int, input().split())
parents = [0] * v
for i in range(v):
  parents[i] = i

line = []
for _ in range(e):
  a,b,c = map(int, input().split())
  line.append((c,(a-1,b-1)))

line.sort()

def findRoot(parent, x):
  if parent[x] != x:
    parent[x] = findRoot(parent,parent[x])
  return parent[x]

def union(parent,a,b):
  a = findRoot(parent,a)
  b = findRoot(parent,b)

  if a<b:
    parent[b] = a
  else:
    parent[a] = b

result = 0
for i in line:
  cost = i[0]
  a,b = i[1]

  if findRoot(parents, a) != findRoot(parents,b):
    union(parents,a,b)
    result += cost
print(result)