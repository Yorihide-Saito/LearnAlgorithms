Q = int(input().strip())
bag = []

for _ in range(Q):
    query = input().strip().split()
    if query[0] == '1':
        bag.append(int(query[1]))
        bag.sort()
    if query[0] == '2':
        print(bag[0])
        bag.pop(0)