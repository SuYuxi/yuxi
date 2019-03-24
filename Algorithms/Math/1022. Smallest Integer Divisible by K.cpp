//Pigeonhole principle
//if there is only K - 1 remainders with K, there will bee a duplicate remainders which
//will cause a modulo loop. So either there is no number divisible by K
//or there is a number which the number is less than or equal K

//1 % 6 = 1
//11 % 6 = 5
//111 % 6 = 3 
//1111 % 6 = 1 equal (111 % 6) * 10 + 1
//11111 % 6 = 5
//111111 % 6 = 3
class Solution {
public:
    int smallestRepunitDivByK(int K) {
		if((K & 1) == 0 || (K % 10) == 5) return -1; //it's optional
		int N = 0;
		for(int bits = 1; bits <= K; bits += 1)
		{
			N = (N * 10 + 1) % K;
			if(N == 0) return bits;
		}
		return -1;
    }
};
