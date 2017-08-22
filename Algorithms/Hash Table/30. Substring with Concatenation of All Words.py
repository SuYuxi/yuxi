#a little like Boyer-Moore
class Solution(object):
	def findSubstring(self, s, words):
		def findstring(start, string, words):
			wordStart = start
			curD = dict()
			while(wordStart < sLen - wLen + 1):
				tempWord = string[wordStart:wordStart+wLen]
				wordStart += wLen
				if(tempWord not in targetD): 
					start= wordStart
					curD.clear()
				else:
					curD[tempWord] = curD.setdefault(tempWord,0) + 1
					while(curD[tempWord] > targetD[tempWord]): 
						curD[string[start:start+wLen]] -= 1
						start += wLen
					if(wordStart - start== senLen):
						ret.append(start)

		if(not words or not s): return []
		sLen = len(s)
		wSize = len(words)
		wLen = len(words[0])
		targetD = dict()
		senLen = wSize * wLen 
		ret = list()
		for key in words:
			targetD[key] = targetD.setdefault(key, 0) + 1
		for inx in range(min(wLen, sLen - senLen + 1)):
			findstring(inx, s, words)
		sorted(ret)
		return ret
