import sys

n = int(sys.stdin.readline())
a=list(map(int, sys.stdin.readline().split()))
a.sort()

m = int(sys.stdin.readline())
b=map(int, sys.stdin.readline().split())

def bin_search(a,key):
 pl =0
 pr = len(a)-1

 while pl<=pr:
  pc = (pl+pr) // 2
  if a[pc] == key:
    print(1)
    return
  elif a[pc] < key:
    pl = pc+1
  else:
    pr = pc-1
 print(0)

for i in b:
  bin_search(a, i)