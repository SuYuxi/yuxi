class Solution(object):
    def reconstructQueue(self, people):
        people.sort(key = lambda i:(-i[0],i[1]))
        L = []
        for i in people:
            L.insert(i[1],i)
        return L
