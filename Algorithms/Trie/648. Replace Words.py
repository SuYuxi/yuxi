#Trie Hash
class Solution(object):
    def replaceWords(self, Dict, sentence):
		def replace(word):
			node = trie
			for letter in word:
				if(letter not in node):
					break
				node = node[letter]
				if('END' in node):
					return node['END']
			return word

		trie = dict()
		for word in Dict:
			node = trie
			for letter in word:
				if(letter not in node):
					node[letter] = dict()
				node = node[letter]
			node['END'] = word
		return ' '.join(map(replace, sentence.split()))

#Trie Tree
class TreeNode(object):
	def __init__(self, val = None):
		self.val = val
		self.subNodes = [None] * 26
		
class Solution(object):
    def replaceWords(self, dict, sentence):
		root = TreeNode()
		for word in dict:
			node = root
			for letter in word:
				ASCII = ord(letter) - 97
				if(not node.subNodes[ASCII]):
					node.subNodes[ASCII] = TreeNode()
				node = node.subNodes[ASCII]
			node.val = word

		words = sentence.split()
		for inx, word in enumerate(words):
			node = root
			for letter in word:
				ASCII = ord(letter) - 97
				if(node.val):
					words[inx] = node.val
					break
				elif(not node.subNodes[ASCII]):
					break
				node = node.subNodes[ASCII]
		return ' '.join(words)

#Hash
class Solution(object):
    def replaceWords(self, dict, sentence):
		def replace(word):
			for i in range(1, len(word)):
				if(word[:i] in Set):
					return word[:i]
			return word
		Set = set(dict)
		return ' '.join(map(replace, sentence.split()))
