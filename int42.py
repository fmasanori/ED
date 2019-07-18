class int42(int):
  def __init__(self, n):
    int.__init__(n)
    
  def __add__(a, b):
    return 42

  def __str__(n):
    return '42'

a = int42(13)
b = int42(7)
print (a + b)
print (a)
print (b)
