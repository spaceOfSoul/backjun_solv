import sys
input = sys.stdin.readline

notHear = {}
notSee = {}

n, m = map(int, input().split())

for i in range(n):
  notHear[input()] = None

for i in range(m):
  notSee[input()] = None


result = []
if m>n:
  keys = notHear.keys()
  for i in keys:
    if i in notSee:
      result.append(i)
else:
  keys = notSee.keys()
  for i in keys:
    if i in notHear:
      result.append(i)

result.sort()
print(len(result))
for i in result:
  print(i.rstrip())