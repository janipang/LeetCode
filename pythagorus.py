import math
a,b = map(float, (input()).split())

c_2 = (a**2) + (b**2)
c = math.sqrt(c_2)
print('%.6f' %c)