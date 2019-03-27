//Least recently used cache
class LRUCache {
public:
    LRUCache(int _capacity) : capacity(_capacity)
							, size(0)
	{
    }
    
    int get(int key) {
		UIPLI::iterator it = cache.find(key);
		if(it == cache.end()) return -1;
		elevate(it);
		return it->second.first;
    }
    
    void put(int key, int value) {
		UIPLI::iterator it = cache.find(key);
		if(it != cache.end())
		{
			elevate(it);
		}
		else
		{
			if(size == capacity)
			{
				cache.erase(pList.back());
				pList.pop_back();
				size -= 1;
			}
				pList.emplace_front(key);
				size += 1;
		}
		cache[key] = {value, pList.begin()};
		return;
    }

private:
	typedef std::list<int> LI;
	typedef std::pair<int, LI::iterator> PLI;
	typedef std::unordered_map<int, PLI> UIPLI;
	
	UIPLI cache;
	LI pList;
	int capacity;
	int size;

	void elevate(UIPLI::iterator it) {
		pList.erase(it->second.second);
		pList.emplace_front(it->first);
		it->second.second = pList.begin();
		return;
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
