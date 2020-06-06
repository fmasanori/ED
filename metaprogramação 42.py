from functools import wraps
def hitchhiker(func):
  @wraps(func)
  def wrapper(*args, **kwargs):
    return 42
  return wrapper

@hitchhiker
def fat(n):
  if n < 2: return 1
  return n * fat(n-1)

@hitchhiker
def fib(n):
  if n < 2: return 1
  return fib(n-1) + fib(n-2)

print ('42 is stronger than 666')
print (f'fat(666)={fat(666)}')
print (f'fib(666)={fib(666)}')
