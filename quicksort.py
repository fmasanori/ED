def quicksort(v):
    if len(v) <= 1: return v
    
    pivô = v[0]
    iguais  = [x for x in v if x == pivô]
    menores = [x for x in v if x <  pivô]
    maiores = [x for x in v if x >  pivô]
    return quicksort(menores) + iguais + quicksort(maiores)

from random import sample
v = sample(range(10), 10)
print (v)
v = quicksort(v)
print (v)









































