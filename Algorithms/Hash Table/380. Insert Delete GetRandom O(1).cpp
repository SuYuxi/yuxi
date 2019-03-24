class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
		if(pos.count(val)) return false;
		pos[val] = nums.size();
		nums.emplace_back(val);
		return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
		if(!pos.count(val)) return false;
		int last = nums.back();
		nums[pos[val]] = last;
		pos[last] = pos[val];
		nums.pop_back();
		pos.erase(val);
		return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
		return nums[rand() % nums.size()];
    }
private:
	unordered_map<int, int> pos;
	vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
