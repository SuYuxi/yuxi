class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0, totalTank = 0; 
        int start = 0;
        for(int i = 0; i < gas.size(); ++i)
        {
            tank += gas[i] - cost[i];
            if(tank < 0)
            {
                totalTank += tank;
                tank = 0;
                start = i + 1;
            }

        }
        return (totalTank + tank < 0) ? -1 : start;
    }
};
