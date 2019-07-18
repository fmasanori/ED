def seleção(v):
  r = []
  while v:
    m = min(v)
    r.append(m)
    v.remove(m)
  return r

from random import sample
v = sample(range(10), 10)
print (v)
v = seleção(v)
print (v)

