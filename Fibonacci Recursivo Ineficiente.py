def fib(n):
  print (f'fib({n})')
  if n <= 2: return 1
  return fib(n-1) + fib(n-2)

print (fib(10))
#dá para calcular fib(100) nesta palestra?
