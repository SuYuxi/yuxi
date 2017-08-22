#recursive
class Solution(object):
    def generateParenthesis(self, n):
		def recursive(parenthesis, left, right):
			if(left):
				recursive(parenthesis + '(', left - 1, right)
			if(left < right):
				recursive(parenthesis + ')', left, right - 1)
			elif(not right):
				L.append(parenthesis)
			return
			
		L = []
		recursive('', n, n)
		return L

#generator
class Solution(object):
    def generateParenthesis(self, n):
		def generator(parenthesis, left, right):
			if(right >= left >= 0):
				if(not right):
					yield parenthesis
				for i in generator(parenthesis + '(', left - 1, right):
					yield i
				for i in generator(parenthesis + ')', left, right - 1):
					yield i
		return [i for i in generator('', n, n)]

