def inserção(v):
  for j in range(1, len(v)):
    x = v[j]
    i = j - 1
    while i >= 0 and v[i] > x:
      v[i+1] = v[i]
      i = i - 1
    v[i + 1] = x
  return v

from random import sample
v = sample(range(10), 10)
print (v)
v = inserção(v)
print (v)
