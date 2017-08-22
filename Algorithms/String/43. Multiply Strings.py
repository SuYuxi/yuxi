class Solution(object):
    def multiply(self, num1, num2):
		l1, l2 = len(num1), len(num2)
		pos = [0] * (l1 + l2)
		for i in range(l1 - 1, -1, -1):
			for j in range(l2 - 1, -1, -1):
				Sum = pos[i + j + 1] + int(num1[i]) * int(num2[j])
				pos[i + j] += Sum // 10
				pos[i + j + 1] =  Sum % 10
		for inx in range(l1 + l2):
			if(pos[inx]):
				return ''.join([str(x) for x in pos[inx:]])
		return '0'
