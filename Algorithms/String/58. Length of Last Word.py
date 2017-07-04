class Solution(object):
    def lengthOfLastWord(self, s):
		temp = str() 
		word = str()
		for c in s:
			if(c != ' '):
				temp += c
			else:
				if(temp):
					word = temp
					temp = str()
		if(temp):
			word = temp
		return len(word)
