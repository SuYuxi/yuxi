class Solution(object):
	def reverseWords(self, s):
		stack = list()
		length = len(s)
		inx = 0
		while(inx < length):
			word = ''
			while(inx < length and s[inx] != ' '):
				word += s[inx]
				inx += 1
			if(word):
				stack.append(word)
			while(inx < length and s[inx] == ' '):
				inx += 1
		ret = ''
		while(stack):
			ret += ' ' + stack.pop()
		return ret[1:]

#worse but in-place solution
class Solution(object):
	def reverseWords(self, s):
		begin = 0
		storeInx = 0
		length = len(s)
		s = list(s)
		s = s[::-1]
		while(begin < length):
			if(s[begin] != ' '):
				inx = begin
				if(storeInx!=0):
					s[storeInx] = ' '
					storeInx += 1
				while(inx < length and s[inx] != ' '):
					s[storeInx] = s[inx]
					inx += 1
					storeInx += 1
				s[storeInx - (inx - begin) : storeInx] = s[storeInx - (inx - begin): storeInx][::-1]
				begin = inx
			begin += 1 
		s = s[:storeInx] 
		return ''.join(s)

#best and fastest solution
class Solution(object):
	def reverseWords(self, s):
		return ' '.join(s.split()[::-1])
