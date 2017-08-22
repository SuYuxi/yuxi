import re
s = input()
W = re.compile(r'W{2,}')
B = re.compile(r'B{2,}')
s = W.sub('W', s)
s = B.sub('B', s)
print(len(s)-1)
