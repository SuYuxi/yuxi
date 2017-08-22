class Solution(object):
    def findDuplicate(self, paths):
		D = dict()
		for path in paths:
			data = path.split()
			for fileinfo in data[1:]:
				name, _, content = fileinfo.partition('(')
				D.setdefault(content[:-1], list()).append(data[0] + '/' + name)
		return [x for x in D.values() if len(x) > 1]
