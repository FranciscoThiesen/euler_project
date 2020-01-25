from math import *

accu = 0
f = open("nums.txt", 'r')
nums = f.readlines()
vals = [int(i) for i in nums]
for x in vals:
	accu = accu + x


a = str(accu)

k = 0
ans = ""
while k < 10:
	ans = ans + a[k]
	k = k + 1
print(ans)