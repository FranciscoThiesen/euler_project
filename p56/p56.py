from math import *

def digiSum(x):
    res = 0
    while x > 0:
        res = res + ( x % 10 )
        x = (x / 10)
    return res

best = 0

for x in xrange(1, 101):
    for y in xrange(1, 101):
        best = max( best, digiSum( x ** y ) )


print( best )
