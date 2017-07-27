# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def insert(self, intervals, newInterval):
		start, end = newInterval.start, newInterval.end
		left = [x for x in intervals if x.end < start]
		right = [x for x in intervals if x.start > end]
		if(left + right != intervals):
			start = min(start, intervals[len(left)].start)
			end = max(end, intervals[-len(right)-1].end)
		return left + [Interval(start, end)] + right

class Solution(object):
    def insert(self, intervals, newInterval):
		if(not intervals):
			return [newInterval]
		intervals = sorted(intervals + [newInterval], key = lambda x: x.start)
		res = [intervals[0]]
		for interval in intervals[1:]:
			cur = res[-1]
			if(cur.end < interval.start):
				res.append(interval)
			elif(cur.end < interval.end):
				cur.end = interval.end
		return res
