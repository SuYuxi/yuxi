class Solution(object):
    def myAtoi(self, s):
        try:
            s = s.lstrip() + '$'
            for i, ch in enumerate(s):
                if not (ch in '+-' or ch.isdigit()): 
                    result = int(s[:i])
                    return -2 ** 31 if result < -2 ** 31 else 2 ** 31 - 1 if result > 2 ** 31 - 1 else result
        except:
            return 0
