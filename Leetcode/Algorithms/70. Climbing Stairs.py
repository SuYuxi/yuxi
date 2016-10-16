#Fibonacci sequence
class Solution(object):
    def climbStairs(self, n):
		if(n == 0 or n == 1)
			return 1
        one_step_before, one_step_before = 1, 1
        for i in range(2,n):
            all_ways = one_step_before + two_step_before
			two_step_before = one_setp_before
			one_step_before = all_ways
        return all_ways

class Solution(object):
    def climbStairs(self, n):
        a, b = 1, 1
        for i in range(n):
            a, b = a + b, a
        return b
