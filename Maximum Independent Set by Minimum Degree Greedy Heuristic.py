G = {}
V = [1, 2, 3, 4, 5, 6, 7]
G[1] = [6, 7]
G[2] = [3, 7]
G[3] = [4, 7, 2]
G[4] = [3, 7]
G[5] = [7]
G[6] = [1, 3]
G[7] = [1, 2, 3, 4, 5]
removed = [False]*8
S = []
aux = []
for i in V: aux.append((i, G[i]))
aux.sort(key=lambda a: len(a[1]))
removed[0] = True
while aux:
    v = aux[0]
    if not removed[v[0]]: S.append(v[0])
    for i in v[1]: removed[i] = True
    aux.pop(0)
print(S)
