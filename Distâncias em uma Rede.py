A = [[0, 1, 0, 0, 0, 0], 
     [0, 0, 1, 0, 0, 0],
     [0, 0, 0, 0, 1, 0],
     [0, 0, 1, 0, 1, 0],
     [1, 0, 0, 0, 0, 0],
     [0, 1, 0, 0, 0, 0]]

def Distancias(n, origem):
  d = [-1] * n
  d[origem] = 0
  f = []
  f.append(origem)
  while len(f) > 0:
    x = f.pop(0)
    for y in range(n):
      if A[x][y] == 1 and d[y] == -1:
        d[y] = d[x] + 1
        f.append(y)
  return d
print (Distancias(6, 3))
