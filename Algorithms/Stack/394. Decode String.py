#regular expression
import re
class Solution(object):
	def decodeString(self, s):
		pattern = re.compile(r'(\d+)\[([a-z]*)\]')	
		while('[' in s):
			s = pattern.sub(lambda x: int(x.group(1)) * x.group(2), s)
		return s

#stack
class Solution(object):
	def decodeString(self, s):
		stack = [['', 1]]
		num = ''
		for c in s:
			if(c.isdigit()):
				num += c
			elif(c == '['):
				stack.append(['', int(num)])	
				num = ''
			elif(c == ']'):
				string, count = stack.pop()
				stack[-1][0] += count * string
			else:
				stack[-1][0] += c
		return stack[-1][0]
