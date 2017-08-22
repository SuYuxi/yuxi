class Solution(object):
    def fizzBuzz(self, n):
        L = []
        for i in range(1, n+1):
            temp = ''
            if(not (i % 3)):
                temp += 'Fizz'
            if(not (i % 5)):
                temp += 'Buzz'
            if(not temp):
                temp += str(i)
            L.append(temp)
        return L
