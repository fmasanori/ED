G = {
  1: [6, 7],
  2: [3, 7],
  3: [4, 7, 2],
  4: [3, 7],
  5: [7],
  6: [1, 3],
  7: [1, 2, 3, 4, 5]
}
def remove(vizinhos):
  for v in vizinhos: del G[v]
  for x in G:
    for y in vizinhos:
      if y in G[x]: G[x].remove(y)

s = []
while G:
  v = sorted(G,
      key=lambda x: len(G[x]))[0]
  s.append(v)
  vizinhos = G[v]
  del G[v]
  remove(vizinhos)
print (s)
