class Solution(object):
	def restoreIpAddresses(self, s):
		def backtrack(s, ip): 
			lenS = len(s)
			lenP = len(ip)
			if(lenS > 3 * (4 - lenP)):
				return
			elif(lenP == 4):
				res.append(".".join(ip))
			else:
				if(lenS > 0):
					backtrack(s[1:], ip + [s[:1]])
					if(s[0] == '0'):
						return
				if(lenS > 1):
					backtrack(s[2:], ip + [s[:2]])
				if(lenS > 2 and int(s[:3]) <= 255):
					backtrack(s[3:], ip + [s[:3]])
			return
			
		res = []
		backtrack(s, [])
		return res
