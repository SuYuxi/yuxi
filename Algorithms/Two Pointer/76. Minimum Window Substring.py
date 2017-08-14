from collections import Counter
class Solution(object):
    def minWindow(self, s, t):
		need, missing = collections.Counter(t), len(t)
		left, L, R = 0, 0, 0
		for right, char in enumerate(s, 1):
			missing -= need[char] > 0
			need[char] -= 1
			if(not missing):
				while(left < right and need[s[left]] < 0):
					need[s[left]] += 1
					left += 1
				if(not R or right - left <= R - L):
					L, R = left, right
		return s[L:R]

from collections import Counter
class Solution(object):
    def minWindow(self, s, t):
		need = collections.Counter(t)
		counter = len(t)
		lenS = len(s)
		left, right = 0, 0
		begin, wLen = 0, float('inf')
		while(right < lenS):
			if(need[s[right]] > 0):
				counter -= 1
			need[s[right]] -= 1
			right += 1
			while(not counter):
				if(right - left < wLen):
					wLen = right - left
					head = left
				if(not need[s[left]]):
					counter += 1
				need[s[left]] += 1
				left += 1
		return s[head:head + wLen] if wLen != float('inf') else ''
