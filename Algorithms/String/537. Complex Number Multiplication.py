class Solution(object):
	def complexNumberMultiply(self, a, b):
		a = map(int, a[:-1].split('+'))
		b = map(int, b[:-1].split('+'))
		return '{0}+{1}i'.format(a[0]*b[0]-a[1]*b[1], a[0]*b[1]+a[1]*b[0])
