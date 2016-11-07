class Solution(object):
	def eraseOverlapIntervals(self, intervals):
		intervals.sort(key = operator.attrgetter('start', 'end'))
		res, pre = 0, float('-inf')
		for cur in intervals:
			if(pre > cur.start):
				res += 1	
			if(not (cur.start < pre < cur.end)):	
				pre = cur.end
		return res
