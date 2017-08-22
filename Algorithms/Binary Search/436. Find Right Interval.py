class Solution(object):
	def findRightInterval(self, intervals):
		def BinarySearch(target, intervals):
			left, right = 0, len(intervals) - 1
			while(left < right):
				mid = (left + right) >> 1
				if(intervals[mid][0] >= target):
					right = mid	
				else:
					left = mid + 1	
			if(intervals[right][0] >= target):
				return intervals[right][1]
			else:
				return -1
		
		indexs = sorted([[val.start, inx] for (inx, val) in enumerate(intervals)])
		ans = []
		for target in intervals: 
			ans.append(BinarySearch(target.end, indexs)) 
		return ans

#bisect
class Solution(object):
	def findRightInterval(self, intervals):
		indexs = sorted([[val.start, inx] for (inx, val) in enumerate(intervals)]) + [[float('inf'), -1]]
		ans = [indexs[bisect.bisect_left(indexs, [i.end])][1] for i in intervals]
		return ans
