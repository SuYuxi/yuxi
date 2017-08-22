class Solution(object):
	def isValid(self, s):
		stack = list()
		Mapping = {'}': '{', ']': '[', ')': '('}
		leftBracket = ['{', '[', '(']
		for char in s:
			if(char in leftBracket):
				stack.append(char)
			elif(char in Mapping):
				if(not stack or stack.pop() != Mapping[char]):
					return False
		return not stack
