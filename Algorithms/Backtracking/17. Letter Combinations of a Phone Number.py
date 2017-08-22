class Solution(object):
	def letterCombinations(self, digits):
		if(not digits):
			return([])
		mapping = {'1':'*', '2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz', '0':' '}
		output = ['']
		for digit in digits:
			tempComb = list()
			for char in mapping[digit]:
				for preComb in output:
					tempComb.append(preComb + char)
			output = tempComb
		return(output)


class Solution(object):
	def letterCombinations(self, digits):
		if(not digits): return([])
		mapping = {'1':'*', '2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz', '0':' '}
		return(reduce(lambda preComb, digit: [x + y for x in preComb for y in mapping[digit]], digits, ['']))


class Solution(object):
	mapping = {'1':'*', '2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz', '0':' '}
	def letterCombinations(self, digits):
		def backtracking(curComb, digits, targetLen):
			if(len(curComb) == targetLen):
				output.append(curComb)
				return 1
			for digit in self.mapping[digits[0]]:
				backtracking(curComb + digit, digits[1:], targetLen)
		
		if(not digits): return([])
		output = list()
		backtracking('', digits, len(digits))
		return(output)
