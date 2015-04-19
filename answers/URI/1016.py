# -*- coding: utf-8 -*-
'''
    URI 1016 - 
    https://www.urionlinejudge.com.br/judge/en/problems/view/1016
    Author: Gustavo Alves
'''
relative = 90 - 60
dist = int(raw_input())
print "%d minutos" % ( ((dist * 1.0) /relative)*60 )