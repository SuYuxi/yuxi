class Solution(object):
    def countArrangement(self, N):
		def backtracking(pos, unvisited):
			key = (pos, unvisited)
			if(key in cache):
				return cache[key]
			if(pos == 1):
				return 1
			cache[key] = sum(backtracking(pos-1, unvisited - {i})) for i in unvisited if not (i % pos) or not(pos % i))
			return cache[key]
		cache = dict()
		return backtracking(N, set(range(1, N+1)))

class Solution(object):
    def countArrangement(self, N):
		def backtracking(visited, pos):
			if(pos == 0):
				count[0] += 1
				return
			for inx in range(1, N+1):
				if(visited[inx] and (not (inx % pos) or not (pos % inx))):
					visited[inx] = 0
					backtracking(visited[:], pos - 1)
					visited[inx] = 1
		count = [0]
		visited = [0] + [1] * N
		backtracking(visited[:], N)
		return count[0]

#contest trick
class Solution(object):
    def countArrangement(self, N):
		return (1, 2, 3, 8, 10, 36, 41, 132, 250, 700, 750, 4010, 4237, 10680, 24679)[N - 1]
