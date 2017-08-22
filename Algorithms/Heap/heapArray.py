class Heap(object):
	def __init__(self, x = list()):
		self._stack = list(x)

	@property
	def value(self):
		return self._stack

	@value.setter
	def value(self, value):
		self._stack = value
		return self._stack

	def _shiftUp(self, inx):
		cur = inx + 1
		upper = cur // 2
		while(cur and self._stack[cur-1] < self._stack[upper-1]):
			self._stack[cur-1], self._stack[upper-1] = self._stack[upper-1], self._stack[cur-1]
			cur = upper
			upper = cur // 2

	def _shiftDown(self, inx):
		size = len(self._stack)
		cur = inx
		lower = cur * 2 + 1 
		while(lower < size):
			if(lower+1 < size and self._stack[lower] > self._stack[lower+1]):
				lower += 1
			if(self._stack[cur] > self._stack[lower]):
				self._stack[cur], self._stack[lower] = self._stack[lower], self._stack[cur] 
			else:
				break
			cur = lower
			lower = cur * 2 + 1 
				
	def pop(self):
		if(self._stack):
			top = self._stack[0]
			self._stack[0] = self._stack[-1]
			self._stack = self._stack[:-1]
			self._shiftDown(0)
			return top

	def push(self, value):
		self._stack.append(value)
		self._shiftUp(-1)
		return self.self._stack

	def replace(self, value):
		if(self._stack):
			top = self._stack[0]
			self._stack[0] = value
			self._shiftDown(0)
			return top
		
	def top(self):
		if(self._stack):
			return self._stack[0]

	def heapify(self):
		for inx in range((len(self._stack) // 2) - 1, -1, -1):
			self._shiftDown(inx)
		return self._stack
