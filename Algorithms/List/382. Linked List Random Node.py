import random
class Solution(object):
	def __init__(self, head):
		self.head = head

	def getRandom(self):
		count = 1
		node = self.head
		while(node):
			if(random.randrange(count) >= (count - 1)):
				val = node.val
			count += 1
			node = node.next
		return val 

import random
class Solution(object):
	def __init__(self, head):
		self.head = head

	def getRandom(self):
		node = self.head
		val = node.val
		before = 0
		N = 100 #Buffer size
		while(node):
			count = 0
			buffer = [0] * N
			while(node and count < N):
				buffer[count] = node.val 
				node = node.next
				count += 1
			point = random.randrange(before + count)
			if(point >= before): 
				val = buffer[point - before]
			before += count
		return val
