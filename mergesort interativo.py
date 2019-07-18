def mergesortInterativo(v):
    b = 1
    n = len(v)
    while b < n:
        p = 0
        while p + b < n:
            r = p + 2*b
            if r > n: r = n
            v[p:r] = merge(v[p:p+b], v[p+b: r])
            p = p + 2 * b
        b = 2*b
    return v

def merge(e, d):
    r = []
    i, j = 0, 0
    while i < len(e) and j < len(d):
        if e[i] <= d[j]:
            r.append(e[i])
            i += 1
        else:
            r.append(d[j])
            j += 1
    r += e[i:]
    r += d[j:]
    return r

from random import sample
v = sample(range(10), 10)
print (v)
v = mergesortInterativo(v)
print (v)



