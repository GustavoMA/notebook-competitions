'''
    URI 1643 - Converter Kilometros para Milhas
    https://www.urionlinejudge.com.br/judge/pt/problems/view/1643
    Tag: greedy
    Author: Gustavo Alves
'''
 
fib = [-1 for i in xrange(22)]
fib[0] = 1
fib[1] = 2
for i in xrange(2,22):
    fib[i] = fib[i-1] + fib[i-2]
fib = tuple(fib)
 
def num_to_fib_representation(n):
    representation = [0 for i in xrange(22)]
    for i in xrange(21, -1, -1):
        if (n - fib[i] >= 0):
            n -= fib[i]
            representation[i] = 1
    return representation
 
def km_to_mile(n):
    m = 0
    representation = tuple(num_to_fib_representation(n))
    for i in xrange(1, 22):
        m += representation[i] * fib[i-1]
    return m
 
n = int(raw_input())
for k in xrange(n):
    m = int(raw_input())
    print km_to_mile(m)