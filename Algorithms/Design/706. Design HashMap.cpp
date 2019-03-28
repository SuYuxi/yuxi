//classical array + linkedList 
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
		size = 1000;
		hash.resize(size);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
		list<pair<int, int>>& l = hash[key % size];
		for(pair<int, int>& p : l)
		{
			if(p.first == key)
			{
				p.second = value;
				return;
			}
		}
		l.emplace_back(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
		list<pair<int, int>>& l = hash[key % size];
		if(l.empty()) return - 1;
		for(pair<int, int>& p : l)
		{
			if(p.first == key)
			{
				return p.second;
			}
		}
		return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
		list<pair<int, int>>& l = hash[key % size];
		l.remove_if([& key](pair<int, int> p) -> bool {return p.first == key;});
    }

private:
	vector<list<pair<int, int>>> hash;
	int size = 1000;
};

//tricky way
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
		hash = vector<int>(10000, -1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
		if(key >= hash.size())
			hash.resize(key + 1, -1);
		hash[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
		if(key >= hash.size())
			return -1;
		return hash[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
		if(key >= hash.size()) return;
		hash[key] = -1;
    }

private:
	vector<int> hash;

};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
