class Solution(object):
    def addBinary(self, a, b):
		inx1, inx2 = len(a)-1, len(b)-1
		res = str()
		carry = str()
		while(inx1 >= 0 or inx2 >= 0):
			count = 0
			if(inx1 >= 0 and a[inx1] == '1'):
				count += 1
			if(inx2 >= 0 and b[inx2] == '1'):
				count += 1
			if(carry):
				count += 1
			if(count == 3):
				res = '1' + res
				carry = '1'
			elif(count == 2):
				res = '0' + res
				carry = '1'
			elif(count == 1):
				res = '1' + res
				carry = str()
			else:
				res = '0' + res
				carry = str()
			inx1 -= 1
			inx2 -= 1
		if(carry):
			res = '1' + res
		return res

class Solution(object):
    def addBinary(self, a, b):
		return bin(int(a, base=2) + int(b, base=2))[2:]
