def inserção(v):
  for j in range(1, len(v)):
    x = v[j]
    i = j - 1
    while i >= 0 and x < v[i]:
      v[i+1] = v[i]
      i = i - 1
    v[i + 1] = x
  return v
from time import time
from random import shuffle
v = list(range(20000))
shuffle(v)
t1 = time()
inserção(v)
t2 = time()
print (t2-t1)
##from random import sample
##v = sample(range(10), 10)
##print (v)
##v = inserção(v)
##print (v)
