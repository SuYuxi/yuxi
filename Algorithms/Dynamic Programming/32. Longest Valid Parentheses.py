#Dynamic Programming
class Solution(object):
    def longestValidParentheses(self, s):
		DP = [0] * len(s)
		res = 0
		inx = 1
		while(inx < len(s)):
			if(s[inx] == ')'):
				if(s[inx-1] == '('):
					DP[inx] = DP[inx-2] + 2 if(inx >= 2) else 2
				elif(inx - DP[inx-1] - 1 >= 0 and s[inx - DP[inx-1] - 1] == '('):
					DP[inx] = DP[inx-1] + 2
					if (inx - DP[inx-1] - 2 >= 0):
						DP[inx] += DP[inx - DP[inx-1] - 2]
				res = max(res, DP[inx])
			inx += 1
		return res

#Stack
class Solution(object):
    def longestValidParentheses(self, s):
		stack = [-1]
		res = 0
		for inx, c in enumerate(s):
			if(c == '('):
				stack.append(inx)
			else:
				stack.pop()
				if(stack):
					res = max(res, inx - stack[-1])
				else:
					stack.append(inx)
		return res

#in-place two counters
class Solution(object):
    def longestValidParentheses(self, s):
		leftCount, rightCount = 0, 0
		res = 0
		for c in s:
			if(c == '('):
				leftCount += 1
			else:
				rightCount += 1
			if(leftCount == rightCount):
				res = max(res, leftCount * 2)
			elif(leftCount < rightCount):
				leftCount, rightCount = 0, 0
		leftCount, rightCount = 0, 0
		for c in s[::-1]:
			if(c == '('):
				leftCount += 1
			else:
				rightCount += 1
			if(leftCount == rightCount):
				res = max(res, leftCount * 2)
			elif(leftCount > rightCount):
				leftCount, rightCount = 0, 0
		return res
