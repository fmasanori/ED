def enumerações(items):
    n = len(items)
    s = [0]*(n+1)
    k = 0
    while True:
        if s[k] < n:
            s[k+1] = s[k] + 1
            k += 1
        else:
            s[k-1] += 1
            k -= 1
        if k == 0: break
        else:
            lista = []
            for j in range(1, k+1):
                lista.append(items[s[j]-1])
            yield lista

def combinações(items, n):
    if n==0: yield []
    else:
        for i in range(len(items)):
            for cc in combinações(items[:i]+items[i+1:],n-1):
                yield [items[i]]+cc

def permutações(items):
    return combinações(items, len(items))

##print ('Permutações')
##for p in permutações([1, 2, 3, 4, 5, 6]):
##    print (p)
##    
##print ('Enumerações')
##for p in enumerações([1, 2, 3, 4, 5, 6]):
##    print (p)
    
##for p in permutações(['Adriano','Bruno', 'Diogo', 'Eclis', 'Gabriel', 'Leandro', 'Walber']):
##    print (p)

##for p in enumerações(['Jessica', 'Fernanda', 'Pamela', 'Renata']):
##    print (p)
