import math

N = int(input().strip())
rSet,cSet = set(), set()

for i in range(N):
    r, c = input().strip().split()
    rSet.add(int(r))
    cSet.add(int(c))

print(max(math.ceil((max(rSet) - min(rSet))/2), math.ceil((max(cSet) - min(cSet))/2)))