from math import *

def iterate( x ):
    t = str(x)
    s = t[::-1]

    print(t, s)
    
    t = int(t)
    s = int(s)
    r = s + t
    return r


def checkPal( x ):
    s = str(x)
    t = s[::-1]
    for x in xrange(len(s)):
        if s[x] != t[x]:
            return False
    return True

def checkLyrichel(x):
    num = x
    for _ in xrange(50):
        num = iterate( num )
        if checkPal(num) == True:
            return False
    return True

count = 0
for x in xrange(1, 10001):
    if checkLyrichel(x) == True:
        count = count + 1
        # print(x)

print( count )
