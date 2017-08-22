#Manacher's Algorithm
class Solution(object):
    def countSubstrings(self, s):
		S = '^#' + '#'.join(s) + '#$'
		length = len(S)
		rad = [0] * length
		center, bounder = 0, 0
		for inx in range(1, length-1):
			if(inx < bounder):
				rad[inx] = min(bounder - inx, rad[2 * center - inx]) 
			while(S[inx + rad[inx] + 1] == S[inx - rad[inx] -1]):
				rad[inx] += 1
			if(inx + rad[inx] > bounder):
				center, bounder = inx, inx + rad[inx]
		return sum((num + 1) / 2 for num in rad)
	
#Straightforward
class Solution(object):
    def countSubstrings(self, s):
		length = len(s)
		ans = 0
		for center in range(2*length-1):
			left = center / 2
			right = left + center % 2
			while(left >= 0 and right < length and s[left] == s[right]):
				ans += 1
				left -= 1
				right += 1
		return ans

#DP
class Solution(object):
    def countSubstrings(self, s):
		length = len(s)
		dp = [[0] * length for _ in range(length)]
		for row in reversed(range(length)):
			for col in range(row, length):
				if(s[row] == s[col]):
					if(row >= col - 2):
						dp[row][col] = 1
					else:
						dp[row][col] = dp[row+1][col-1]
		return sum(map(sum, dp))
