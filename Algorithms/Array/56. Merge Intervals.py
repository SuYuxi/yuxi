# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
		if(not intervals):
			return list()
		intervals = sorted(intervals, key = lambda x: x.start)
		res = [intervals[0]]
		for interval in intervals[1:]:
			cur = res[-1]
			if(cur.end < interval.start):
				res.append(interval)
			elif(cur.end < interval.end):
				cur.end = interval.end
		return res
