from collections import defaultdict
S = input()
wordDict = defaultdict(int)
freqDict = defaultdict(list)
freqIndex = [] 
L = []
for i in range(len(S) - 1):
	temp = S[i] + S[i + 1]
	wordDict[temp] += 1
for i in wordDict:
	freqDict[wordDict[i]].append(i)
for i in freqDict:
	freqIndex.append(i)
freqIndex = sorted(freqIndex, reverse = True)
for i in freqIndex:
	L += sorted(freqDict[i],reverse = False)
for i in L:
	print(i)
