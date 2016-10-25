class Solution(object):
	def twoSum(self, numbers, target):
		def binarysearch(val, numbers):
			pointer = scale = len(numbers) // 2
			while(scale != 0):
				if(numbers[pointer] == val):
					return pointer
				elif(numbers[pointer] < val):
					scale //= 2
					pointer -= scale 
				else:
					scale //= 2
					pointer += scale
			
		for inx1 in range(len(numbers)):
			val = target - numbers[inx1]
			inx2 = binarysearch(val, numbers)
			if(inx2):
				return [inx1 + 1, inx2 + 1]

class Solution(object):
	def twoSum(self, numbers, target):
		p1, p2 = 0, len(numbers) - 1
		while(numbers[p1] + numbers[p2] != target):
			if(numbers[p1] + numbers[p2] < target):
				p1 += 1
			else:
				p2 -= 1
		return [p1 + 1, p2 + 1]

