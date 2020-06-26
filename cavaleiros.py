f = open('cavaleiros.txt')
amigos = {}
for linha in f:
  linha = linha.strip().split()
  amigos[linha[0]] = linha[1:]
print (amigos)

  


