import re
p = re.compile(r'\d+')
d, m, a = p.findall('09-03-2018')
print (d, m, a)
d, m, a = p.findall('09/03/2018')
print (d, m, a)

a, m, d = p.findall('6(anos) 2(meses) 10(dias)')
print(a, m, d)
a, m, d = p.findall('6a2m10d')
print(a, m, d)
