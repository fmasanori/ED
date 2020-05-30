dic = {}
def fib(n):
  if n <= 2: return 1
  if n not in dic:
    dic[n] = fib(n-1) + fib(n-2)
  return dic[n]
print (fib(100))
