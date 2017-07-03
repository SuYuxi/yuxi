class Solution(object):
    def findCircleNum(self, M):
		def traverse(relation):
			for inx, status in enumerate(relation): 
				if(status and not map[inx]):
					map[inx] = 1
					traverse(M[inx])
			
		size = len(M)
		map = [0] * size
		res = 0
		for inx, relation in enumerate(M) :
			if(map[inx]):
				continue
			res += 1
			traverse(relation)
		return res
