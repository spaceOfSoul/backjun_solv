import sys

n = int(sys.stdin.readline())
deck = list(map(int, sys.stdin.readline().split()))
deck.sort()

m = int(sys.stdin.readline())
searchV = list(map(int, sys.stdin.readline().split()))

dic = {}

def bs(arr, key):
  count = 0
  pr = 0
  pl = len(arr) - 1

  while True:
    pc = (pr + pl) // 2
    if arr[pc] == key:
      count += 1
      for i in range(pc -1, -1, -1):
        if arr[i] == key:
          count+=1
        else:
          break
      for i in range(pc+1,len(arr)):
        if arr[i] == key:
          count+=1
        else:
          break
      break
    elif arr[pc] < key:
      pr = pc + 1 
    else:
      pl = pc -1
    
    if pr > pl:
      break
  
  return count

for i in deck:
  if i not in dic:
    dic[i] = bs(deck, i)

for i in searchV:
  if i in dic:
    print(dic[i], end = ' ')
  else:
    print('0', end = ' ')