class Solution(object):
	def detectCapitalUse(self, word):
		return word.islower() or word.isupper() or word.istitle()

class Solution(object):
	def detectCapitalUse(self, word):
		count = 0
		for c in word:
			if(c <= 'Z'):
				count += 1
		if(count == 1):
			return word[0] <= 'Z'
		return count == 0 or count == len(word)
