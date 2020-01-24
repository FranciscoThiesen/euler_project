from math import *

fat = [1]
for x in xrange(1, 101):
    fat.append( fat[-1] * x )

def n_choose_k(n, k):
    return fat[n] / ( fat[k] * fat[n - k] )

resp = 0

for x in xrange(1, 101):
    for y in xrange( 1, x ):
        if n_choose_k(x, y) > 1000000:
            resp = resp + 1


print (resp )

