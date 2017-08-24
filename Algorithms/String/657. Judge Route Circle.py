class Solution(object):
    def judgeCircle(self, moves):
		return moves.count('L') == moves.count('R') and moves.count('U') == moves.count('D')
		'''
		horizontal, vertical = 0, 0
		for direction in moves:
			if(direction == 'U'):
				vertical += 1
			elif(direction == 'D'):
				vertical -= 1
			elif(direction == 'R'):
				horizontal += 1
			elif(direction == 'L'):
				horizontal -= 1
		return not horizontal and not vertical
		'''
