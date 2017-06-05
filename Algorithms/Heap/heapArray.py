class Heap(object):
	def __init__(self, x = list()):
		self._stack = list(x)

	@property
	def value(self):
		return self._stack

	@value.setter
	def val(self, value):
		self._stack = value
		return self._stack

	def _shiftUp(self, inx):
		cur = inx + 1
		upper = cur // 2
		while(cur && _stack[cur-1] < _stack[upper-1]):
			_stack[cur-1], _stack[upper-1] = _stack[upper-1], _stack[cur-1]
			cur = upper
			upper = cur // 2

	def _shiftDown(self, inx):
		size = len(_stack)
		cur = inx
		lower = cur * 2 + 1 
		while(lower < size):
			if(_stack[cur] > _stack[lower]

	def pop(self):
		if(x):
			top = x[0]
			x[0] = x[-1]
			x = x[:-1]
			_shiftDown(0)
			return top

	def push(self, value):
		_stack.append(value)
		_shiftUp(-1)
		return self._stack

	def replace(self, value):
		if(x):
			top = x[0]
			x[0] = value
			_shiftDown(0)
			return top
		
	def top(self):
		if(x):
			return x[0]

	def heapify(self):
		for inx in range((len(self._stack) // 2) - 1, -1, -1):
			_shiftDown(inx)
		return self._stack
