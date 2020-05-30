g = {}
g[1] = [6, 7]
g[2] = [3, 7]
g[3] = [2, 4, 6, 7]
g[4] = [3, 7]
g[5] = [7]
g[6] = [1, 3]
g[7] = [1, 2, 3, 4, 5]
removidos = [True] + len(g) * [False]
def mínimo():
  m = removidos.index(False)
  for v in g:
    if removidos[v]: continue
    if len(g[v]) < len(g[m]): m = v
  return m
def remove_vizinhos(v):
  removidos[v] = True
  for x in g[v]:
    removidos[x] = True
    g[x] = []
    for y in g:
      if x in g[y]:
        g[y].remove(x)
s = []
while False in removidos:
  v = mínimo()
  s.append(v)
  remove_vizinhos(v)
print (s)
