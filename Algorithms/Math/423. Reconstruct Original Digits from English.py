#fine unique character of num
class Solution(object):
	def originalDigits(self, s):
		D = dict()
		for c in ref
			D[c] = D.setdefault(c, 0) + 1
		ref = [('z', 'zero', 0), ('w', 'two', 2), ('x','six', 6), ('g', 'eight', 8), ('h', 'three', 3), ('u', 'four', 4), ('o','one', 1), ('f', 'five', 5), ('s', 'seven', 7), ('i', 'nine', 9)]
		
		L = []
		for keyword in ref:
			t_key = D.setdefault(keyword[0], 0)
			if(t_key):
				for i in range(t_key):
					L.append(str(keyword[2]))	
				for c in keyword[1]:
					D[c] = D[c] - t_key
		return ''.join(sorted(L))

#super faster solution
from collections import defaultdict
class Solution(object):
	def originalDigits(self, s):
		L = ''
		D = defaultdict(int)
		ref = 'zowhufxsgi'
		for c in ref:
			D[c] = s.count(c)
		num = [0] * 10
		for i in range(0, 10, 2):
			num[i] = D[ref[i]]
		num[3] = D[ref[3]] - num[8]
		num[5] = D[ref[5]] - num[4]
		num[7] = D[ref[7]] - num[6]
		num[1] = D[ref[1]] - num[0] - num[2] - num[4]
		num[9] = D[ref[9]] - num[5] - num[6] - num[8]
		for i in range(10):
			L = L + str(i) * num[i]
		return L
