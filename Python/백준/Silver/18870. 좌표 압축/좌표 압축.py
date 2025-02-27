import sys
input = sys.stdin.readline

n = int(input())

arr = list(map(int, input().split()))
sortArr = sorted(arr)
dictionary = {}

dictionary = dict.fromkeys(sortArr)
j=0
for i in dictionary.items():
  dictionary[i[0]] = j
  j += 1

result = []
for i in arr:
  result.append(dictionary[i])

for i in result:
  print(i, end=' ')