//Greedy
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> counter;
        int maxCount = 0;
        int maxNum = 0;
        for(char& task : tasks)
        {
            counter[task] += 1;
            if(counter[task] > maxNum)
            {
                maxNum = counter[task];
                maxCount = 1;
            }
            else if (counter[task] == maxNum) maxCount += 1;
        }
        
        int partNum = maxNum - 1;
        int partLen = n - maxCount + 1;
        int slots = partNum * partLen;
        int availableTasks = tasks.size() - maxNum * maxCount;
        int idle = max(0, slots - availableTasks);
        return tasks.size() + idle;   
    }
};

//Heap
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> counter;
        priority_queue<int, vector<int>, less<int>> heap;
        deque<int> coolDownList(n, 0);
        int coolDownTime = 0;
        int unitTime = 0;
        for(char& task : tasks)
        {
            counter[task] += 1;
        }
        
        for(pair<const char, int>& p : counter)
        {
            heap.emplace(p.second);
        }
        
        while(!heap.empty() || coolDownTime != 0)
        {
            if(!heap.empty())
            {
                coolDownList.emplace_back(heap.top() - 1);
                coolDownTime += heap.top() - 1;
                heap.pop();
            }
            else
            {
                coolDownList.emplace_back(0);
            }
            if(coolDownList.front() > 0) 
            {
                heap.emplace(coolDownList.front());
                coolDownTime -= coolDownList.front();
            }
            coolDownList.pop_front();
            unitTime += 1;
        }

        return unitTime;
    }
};
