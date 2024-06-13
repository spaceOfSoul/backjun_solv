nums = []
result = [0,0]
for i in range(9):
  n=int(input())
  nums.append(n)
  if len(nums) == 1:
    result[0], result[1] = n, i+1
    continue
  if n > result[0]:
    result[0],result[1] = n, i+1

for i in result:
  print(i)