from time import time
from random import shuffle
v = list(range(20000))
shuffle(v)
t1 = time()
v.sort()
t2 = time()
print (t2-t1)
