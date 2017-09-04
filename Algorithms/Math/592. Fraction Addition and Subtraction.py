class Solution(object):
    def fractionAddition(self, expression):
		def getGcd(a, b):
			if(a == 0 or b == 0): return a + b
			return getGcd(b, a%b)

		begin, end = 0, 1
		A, B = 0, 1
		expression += '+'
		for c in expression[1:]:
			if(c == '-' or c == '+'):
				a, b = map(int, expression[begin:end].split('/'))
				A = a * B + A * b
				B *= b
				begin = end
			end += 1
		gcd = getGcd(A, B)
		A //= gcd
		B //= gcd
		return str(A) + '/' + str(B)
