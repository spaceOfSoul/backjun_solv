import sys


def qsort(a, b, left: int, right: int) -> None:
    pl = left
    pr = right
    mid = (left + right) // 2
    x = b[mid]
    pivot_a = a[mid]

    while pl <= pr:
        while b[pl] < x or (b[pl] == x and a[pl] < pivot_a):
            pl += 1
        while b[pr] > x or (b[pr] == x and a[pr] > pivot_a):
            pr -= 1
        if pl <= pr:
            a[pl], a[pr] = a[pr], a[pl]
            b[pl], b[pr] = b[pr], b[pl]
            pl += 1
            pr -= 1

    if left < pr:
        qsort(a, b, left, pr)
    if pl < right:
        qsort(a, b, pl, right)


def quick_sort(a, b) -> None:
    qsort(a, b, 0, len(b) - 1)


num = int(sys.stdin.readline())
x = [None] * num
y = [None] * num

for i in range(num):
    x[i], y[i] = map(int, sys.stdin.readline().split())

quick_sort(x, y)

for i in range(num):
    print(x[i], y[i])
