from itertools import permutations
def ReadInput():
	return [int(i) for i in input().split(" ")]
(N, K) = ReadInput()
nums = ReadInput()
permu = list(permutations(nums, N))
result = K

def recursive(pointer, pre):
	if(pointer == N): 
		tempVal.append(abs(K - pre))
		return
	recursive(pointer + 1, pre + L[pointer])
	recursive(pointer + 1, pre * L[pointer])
	return  
	
for L in permu:
	tempVal = []
	recursive(1, L[0])
	ans = min(tempVal)
	result = ans if ans < result else result
print(result)
