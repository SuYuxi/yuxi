class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for(int& num : nums)
        {
            add(num);
        }
    }
    
    int showFirstUnique() {
        while(!queue.empty())
        {
            if(hash[queue.front()] == 1)
            {
                return queue.front();
            }
            else
            {
                queue.pop_front();
            }
        }
        return -1;
    }
    
    void add(int value) {
        hash[value] += 1;
        if(hash[value] == 1)
        {
            queue.emplace_back(value);
        }
    }
    
private:
    unordered_map<int, int> hash;
    deque<int> queue;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
