class Solution(object):
	def findWords(self, words):
		S = [set('qwertyuiop'), set('asdfghjkl'), set('zxcvbnm')]
		ret = list()
		for word in words:
			temp = set(word.lower())
			for sub in S:
				if(temp.issubset(sub)):
					ret.append(word)
					break
		return ret

class Solution(object):
    def findWords(self, words):
        return filter(re.compile('(?i)([qwertyuiop]*|[asdfghjkl]*|[zxcvbnm]*)$').match, words)
        return filter(re.compile('([qwertyuiop]*|[asdfghjkl]*|[zxcvbnm]*)$', re.I).match, words)
