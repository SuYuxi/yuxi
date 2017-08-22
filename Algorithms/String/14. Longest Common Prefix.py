class Solution(object):
	def longestCommonPrefix(self, strs):
		if(not len(strs)):
			return ""
		ref = strs[0] 
		comL = len(ref)
		for s in strs[1:]:
			comL = min(comL, len(s))
			for inx in range(comL):
				if(ref[inx] != s[inx]):
					comL = inx
					break
		return ref[:comL]
