import re
import operator
class Solution(object):
	def diffWaysToCompute(self, input):
		def dp(left,right):
			if(left == right):
				return [nums[left]]
			L = []	
			for i in range(left, right):	
				L += [oper[i](a, b) for a in dp(left, i) for b in dp(i + 1, right)]
			return L

		tokens = re.split('(\D)', input)
		nums = [int(i) for i in tokens[::2]]
		oper = map({'-': operator.sub, '+': operator.add, '*': operator.mul}.get, tokens[1::2])
		return dp(0, len(nums) - 1)
