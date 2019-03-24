//Lagrange's Four Square theorem
//Legendre's three-square theorem
class Solution {
public:
    int numSquares(int n) {
		if(isSquare(n)) return 1;

		int sqrtN = sqrt(n);
		while(sqrtN > 0)
		{
			if(isSquare(n - pow(sqrtN, 2)))	return 2;
			sqrtN -= 1;
		}

		while((n & 3) == 0) n >>= 2;
		if((n & 7) == 7) return 4;

		
		return 3;
	}

private:
	bool isSquare(int n) {
		int sqrtN = sqrt(n);
		return pow(sqrtN, 2) == n;
	}
};
