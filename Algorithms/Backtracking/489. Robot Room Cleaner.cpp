/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

//hash by bit operation
class Solution {
public:
    void cleanRoom(Robot& robot) {
		visited.clear();
		backTracking(robot, 0, 1 << 16, 1 << 16); 
    }

private:
	//unordered_map<int, unordered_map<int, int>> visited;
	unordered_set<int64_t> visited;
	const int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

	void backTracking(Robot& robot, int dir, int x, int y) {
		
		robot.clean();
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dirs[dir][0];
			int ny = y + dirs[dir][1];
			int64_t hash = int64_t(nx) << 32 | ny;

			if(!visited.count(hash) && robot.move())
			{
				visited.insert(hash);
				backTracking(robot, dir, nx, ny);
			}
			robot.turnRight();
			dir = (dir + 1) % 4;
		}
		goBack(robot);
	}

	void goBack(Robot& robot) { //go back to the previous position and turn back to the prev direction.
		robot.turnRight();
		robot.turnRight();
		robot.move();
		robot.turnRight();
		robot.turnRight();
	}
};

//hash by nested unordered_map
class Solution {
public:
    void cleanRoom(Robot& robot) {
		visited.clear();
		backTracking(robot, 0, 0, 0); 
    }

private:
	unordered_map<int, unordered_map<int, int>> visited;
	const int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

	void backTracking(Robot& robot, int dir, int x, int y) {
		visited[x][y] = 1;
		robot.clean();
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dirs[dir][0];
			int ny = y + dirs[dir][1];

			if(visited[nx][ny] != 1 && robot.move())
			{
				backTracking(robot, dir, nx, ny);
			}
			robot.turnRight();
			dir = (dir + 1) % 4;
		}
		goBack(robot);
	}

	void goBack(Robot& robot) { //go back to the previous position and turn back to the prev direction.
		robot.turnRight();
		robot.turnRight();
		robot.move();
		robot.turnRight();
		robot.turnRight();
	}
};
