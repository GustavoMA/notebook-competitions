'''
    URI 1046 - Tempo de Jogo
    https://www.urionlinejudge.com.br/judge/en/problems/view/1046
    Author: Gustavo Alves
'''

a, b = map(int, raw_input().split())

if a == b:
	print "O JOGO DUROU 24 HORA(S)"
elif a < b:
	print "O JOGO DUROU %d HORA(S)" % (b - a)
else:
	print "O JOGO DUROU %d HORA(S)" % (24 - a + b)
