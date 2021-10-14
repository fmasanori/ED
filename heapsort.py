from heapq import heappush, heappop
def heapsort(v):
  h = []
  for x in v: heappush(h, x)
  return [heappop(h) for i in range(len(h))]

from time import time
from random import shuffle
v = list(range(20000))
shuffle(v)
t1 = time()
heapsort(v)
t2 = time()
print (t2-t1)
##from random import sample
##v = sample(range(10), 10)
##print (v)
##v = heapsort(v)
##print (v)
