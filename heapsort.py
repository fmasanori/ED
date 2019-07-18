from heapq import heappush, heappop
def heapsort(v):
  h = []
  for x in v:
    heappush(h, x)
  return [heappop(h) for i in range(len(h))]

from random import sample
v = sample(range(10), 10)
print (v)
v = heapsort(v)
print (v)
