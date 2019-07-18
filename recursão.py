def pot(x, n):
  if n == 0: return 1
  return x * pot(x, n-1)

def inv(s):
  if len(s) <= 1: return s
  return inv(s[1:]) + s[0]

def mdc(a, b):
  if a % b == 0: return b
  return mdc(b, a%b)

def sd(n):
  if n <= 9: return n
  return sd(n//10) + n % 10

def dec2bin(n):
  if n == 0: return ''
  return dec2bin(n // 2) + str(n % 2)

print (pot(2, 3))
print (mdc(21, 15))
print (mdc(15, 21))
print (sd(123))
print (dec2bin(18))
