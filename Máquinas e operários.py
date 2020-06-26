G = {
     1:['B'],
     2:['A', 'B', 'E', 'F'],
     3:['A', 'B', 'C'],
     4:['B', 'E'],
     5:['B', 'E', 'F']
}
while G: 
  m = sorted(G, key=lambda x: len(G[x]))[0]
  op = G[m][0]
  print (m, op)
  del G[m]
  for máq in G:
    if op in G[máq]: G[máq].remove(op)
