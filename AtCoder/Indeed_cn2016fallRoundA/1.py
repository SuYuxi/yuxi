import re
s = input()
pattern = re.compile(r'ra')
ans = pattern.sub('', s)
print(ans)
