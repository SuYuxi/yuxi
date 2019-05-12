class Solution {
public:
    bool isRobotBounded(string instructions) {
		vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		int cntD = 0;
		int x = 0, y = 0;
		for(char& c : instructions)
		{
			switch(c){
			case 'L':
				cntD = (cntD - 1 + 4) % 4;
				break;
			case 'R':
				cntD = (cntD + 1) % 4;
				break;
			case 'G':
				x += dirs[cntD][0];
				y += dirs[cntD][1];
				break;
            }
		}
		return (x == 0 && y == 0) || cntD != 0;
    }
};
