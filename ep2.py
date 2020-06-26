from Merlin import *

f = open('casamento no.txt')
damas = []
queridos = {}
for linha in f:
  linha = linha.strip().split()
  queridos[linha[0]] = linha[1:]
  damas.append(linha[0])
print (queridos)

for s in enumerações(damas):
  lista = []
  for d in s:
    lista.extend(queridos[d])
  if len(s) > len(set(lista)):
    print ('Não é possível casar todas')
    s = ' e '.join(s)
    lista = ' '.join(set(lista))
    print (f'{s} gostam de {lista}')
    break
else:
  print ('Possível casar todas')
print ()

f = open('cavaleiros no.txt')
amigos = {}
cavaleiros = []
for linha in f:
  linha = linha.strip().split()
  amigos[linha[0]] = linha[1:]
  cavaleiros.append(linha[0])
print (amigos)

for p in permutações(cavaleiros):
  for k in range(len(p)):
    if p[k] not in amigos[p[(k+1)%len(p)]]:
      break
  else:
    print ('Conseguimos uma mesa')
    print (' '.join(p))
    break
else:
  print ('Não é possível mesa')
    
  


    
    

    
    
    

  


