x = 2 ** 1000
s = str(x)
res = 0
for c in s:
    val = ord(c) - ord('0')
    res = res + val

print(res)
