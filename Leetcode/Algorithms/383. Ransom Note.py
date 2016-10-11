class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        d = dict()
        for i in magazine:
            d[i] = d.setdefault(i,0) + 1
        for j in ransomNote:
            if(d.setdefault(j,0)):
                d[j] -= 1
            else:
                return False
        return True
