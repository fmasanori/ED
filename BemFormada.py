def BemFormada(s):
  p = []
  for c in s:
    if c == ')':
      if p[-1] == '(': p.pop()
      else: return False
    elif c == '}':
      if p[-1] == '{': p.pop()
      else: return False
    else:
      p.append(c)
  return len(p) == 0
print (BemFormada('((){()})'))
print (BemFormada('({)}'))

