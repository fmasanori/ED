import ast
import codegen
expr='''
def answer():
   print ('Hello World')
'''
p = ast.parse(expr)
p.body[0].body = \
    [ast.parse('return 42').body[0]]
print(codegen.to_source(p))

