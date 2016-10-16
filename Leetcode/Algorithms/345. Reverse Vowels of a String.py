class Solution(object):
    def reverseVowels(self, s):
        s = list(s)
        d = set(['a','e','i','o','u','A','E','I','O','U'])
        i = 0
        j = len(s) - 1
        while(i < j):
            while(s[i] not in d and i < j):
                i += 1
            while(s[j] not in d and i < j):
                j -= 1
            s[i], s[j] = s[j], s[i]
            i += 1
            j -= 1
        return ''.join(s)

#Regular Expression
import re
class Solution(object):
    def reverseVowels(self, s):
        pattern = re.compile(r'[aeiou]', re.I)
        stack = pattern.findall(s)
        return pattern.sub(lambda rep: stack.pop(), s)
