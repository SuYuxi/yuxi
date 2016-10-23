import re
s = input()
pattern = re.compile(r'C.*F')
match = pattern.search(s)
if match:
	print('Yes')
else:
	print('No')
