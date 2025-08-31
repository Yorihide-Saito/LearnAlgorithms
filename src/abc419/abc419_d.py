N,M = map(int, input().strip().split())
S = list(input().strip())
T = list(input().strip())

diff = [0]*(N+1)
for _ in range(M):
    L, R = map(int, input().split())
    diff[L-1] += 1
    diff[R] -= 1

res = []
cur = 0
for i in range(N):
    cur += diff[i]
    if cur % 2 == 0:
        res.append(S[i])
    else:
        res.append(T[i])

print(''.join(res))