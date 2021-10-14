import time, random

N = 1000000
NL = 100000   #100000 10 1
origem = [random.randrange(N) for x in range(N)]
lista = list(origem)
t = time.time()
lista.sort(reverse=True)
print (time.time() - t)

import heapq
lista = list(origem)
t = time.time()
maiores = heapq.nlargest(NL, lista)
print (time.time() - t)

lista = list(origem)
t = time.time()
m = max(lista)
print (time.time() - t)
