//topological sort
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<bool> courses(numCourses, false);
		unordered_set<int> visited;

		vector<int> requisites(numCourses, -1);
		for(pair<int, int>& req : prerequisites)
		{		
			requisites[req.first] = req.second;
		}

		for(int inx = 0; inx < numCourses; inx += 1)
		{
			if(courses[
		}
        
    }
};
