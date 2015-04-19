# -*- coding: utf-8 -*-
'''
    URI 1043 - Triangle
    https://www.urionlinejudge.com.br/judge/en/problems/view/1043
    Author: Gustavo Alves
'''

a, b, c = map(float, raw_input().split())

if a < b + c and b < a + c and c < a + b:
	print "Perimetro = %.1f" % (a+b+c)
else:
	print "Area = %.1f" % (((a+b) * c)/2)