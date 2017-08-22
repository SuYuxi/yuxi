class Solution(object):
    def myPow(self, x, n):
		if(n < 0):
			return self.myPow(1/x, -n)
		square = [1, x]
		order = 2
		while(order <= n):
			square.append(square[-1] ** 2)
			order *= 2
		res = 1
		residual = n
		for inx in reversed(range(len(square))):
			order /= 2
			if(residual >= order): 
				res *= square[inx]
				residual -= order 
		return res
