n = 18
p = []
while n:
  p.append(n % 2)
  n = n // 2
while p:
  print (p.pop(), end = '')
