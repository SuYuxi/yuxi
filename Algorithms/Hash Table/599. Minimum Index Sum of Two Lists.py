class Solution(object):
    def findRestaurant(self, list1, list2):
        hashmap = dict()
        com = dict()
        for inx, name in enumerate(list1):
            hashmap[name] = inx
        for inx, name in enumerate(list2):
            if(name in hashmap):
                count = inx + hashmap[name]
                com[count] = com.setdefault(count, []) + [name]
        return com[min(com.keys())] if len(com) else []
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
