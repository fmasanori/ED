def boyermoore(p, t): 
    m = len(p)
    n = len(t)
    if m > n: return -1 
    pulo = [m for k in range(256)] 
    for k in range(m - 1): pulo[ord(p[k])] = m-k-1
    pulo = tuple(pulo)
    k = m - 1
    while k < n:
        j = m - 1
        i = k
        while j >= 0 and t[i] == p[j]: 
            j -= 1
            i -= 1
        if j == -1: return i + 1
        k += pulo[ord(t[k])] #dou "pulos" > 1
    return -1

texto = 'os algoritmos de ordenação'
palavra = 'algoritmo'
print (boyermoore(palavra, texto))
