class Solution(object):
    def fullJustify(self, words, maxWidth):
		cur, res = list(), list()
		length = 0
		for word in words:
			lenCur = len(cur)
			if(length + lenCur + len(word) > maxWidth):
				for inx in range(maxWidth - length):
					cur[inx % (lenCur - 1 or 1)] += ' '
				res.append(''.join(cur))
				cur, length = list(), 0
			cur.append(word)
			length += len(word)
		res.append(' '.join(cur).ljust(maxWidth))
		return res
