//Least Frequently Used Cache
using namespace std;
class LFUCache {
public:
    LFUCache(int _capacity) : capacity(_capacity)
							, size(0)
							, minFreq(0)
							{}
    
    int get(int key) {
		if(hash.count(key) == 0) return -1;
		int value = hash[key].first;
		int freq = hash[key].second++;
		hashList[freq].erase(hashIter[key]);
		hashList[freq + 1].emplace_front(key);
		hashIter[key] = hashList[freq + 1].begin();	
		if(hashList[minFreq].empty())
		{
			minFreq += 1;
		}

		return value;
    }
    
    void put(int key, int value) {
		if(capacity <= 0) return; //important
		if(hash.count(key) != 0)
		{
			int freq = hash[key].second++;
			hashList[freq].erase(hashIter[key]);
			hashList[freq + 1].emplace_front(key);
			hashIter[key] = hashList[freq + 1].begin();	
			hash[key].first = value;
			if(hashList[minFreq].empty())
			{
				minFreq += 1;
			}
			return;
		}
		if(size == capacity)
		{
			int k = hashList[minFreq].back();
			hashList[minFreq].pop_back();
			hash.erase(k);
			hashIter.erase(k);
			size -= 1;
		}
		minFreq = 1;
		hash[key] = {value, minFreq};
		hashList[minFreq].emplace_front(key);
		hashIter[key] = hashList[minFreq].begin();
		size += 1;
    }

private:
	unordered_map<int, pair<int, int>> hash; //key to value and frequency
	unordered_map<int, list<int>::iterator> hashIter; //key to iter
	unordered_map<int, list<int>> hashList;//frequency to list
	int capacity;
	int size;
	int minFreq;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

