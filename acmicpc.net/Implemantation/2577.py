import sys
sc = lambda: sys.stdin.readline()
sys.stdin = open('input.txt', 'r')

A = int(sc())
B = int(sc())
C = int(sc())
list = [0]*10

ans = str(A*B*C)

for i in range(0, len(ans)):
    list[int(ans[i])] += 1

for i in range(0, 10):
    print(list[i])