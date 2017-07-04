#DFS
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
	
#Union find (full version)
class Solution(object):
    def findCircleNum(self, M):
		def find(no, union):
			depth = 1
			while(union[no] != no):
				no, union[no] = union[no], union[union[no]]
				depth += 1
			return (no, depth)

		length = len(M)
		Id = [i for i in range(length)]
		group = length
		for r in range(length): 
			for l in range(r + 1, length):
				if(M[r][l]):
					idR, depthR = find(r, Id)
					idL, depthL = find(l, Id)
					if(idR != idL):
						group -= 1
						if(depthL > depthR):
							Id[idR] = idL
						else:
							Id[idL] = idR
		return group
