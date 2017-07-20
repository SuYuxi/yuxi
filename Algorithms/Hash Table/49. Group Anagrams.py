#Genius Idea using prime number as orthogonal basis
class Solution(object):
    def groupAnagrams(self, strs):
		primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101]
		D = dict()
		for s in strs:
			key = 1
			for c in s:
				key *= primes[ord(c) - 97] 
			D.setdefault(key, list()).append(s)
		return D.values()

class Solution(object):
    def groupAnagrams(self, strs):
		D = dict()
		for s in strs:
			D.setdefault(''.join(sorted(s)), list()).append(s)
		return D.values()
