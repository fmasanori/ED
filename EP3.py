##m='''
##010
##111
##000
##101'''.split()
##m='''
##10101
##10101
##11111'''.split()
m = '''
0011001010
0110001010
0011001110
0000000000
0010001010
0010011111
1111100000
0010001110
0010001110'''.split()
m = [list(x) for x in m]
for x in m: print (' '.join(x))
print()
regiões = []
lin = len(m)
col = len(m[0])
def cima(x, y):
  if x == -1: return False
  return m[x][y] == '1'
def esq(x, y):
  if y == -1: return False
  return m[x][y] == '1'
def regindex(x, y):
  for k in range(len(regiões)):
    for coord in regiões[k]:
      if (x, y) == coord:
        return k
  else:
    return -1
for j in range(lin):
  for k in range(col):
    if m[j][k] == '1':
      rcima = resq = -1
      if cima(j-1, k): rcima = regindex(j-1, k) 
      if esq(j, k-1): resq = regindex(j, k-1)
      if rcima != -1:
        regiões[rcima].append((j, k))
      if resq != -1:
        if rcima != -1:
          if rcima == resq: continue
          regiões[rcima].extend(regiões[resq])
          del regiões[resq]
        else:
          regiões[resq].append((j, k))
      if rcima == resq == -1:
        regiões.append([(j, k)])
cont = ord('1')
for r in regiões:
  for j, k in r:
    m[j][k] = chr(cont)
  cont = cont + 1
for linha in m:
  print (' '.join(linha))
  
