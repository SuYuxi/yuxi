class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> cnt;
        for(int& num : arr1) cnt[num]++;
        vector<int> res;
        for(int& num : arr2)
        {
            for(int i = 0; i < cnt[num]; i++) res.emplace_back(num);
			cnt.erase(num);
        }
        for(auto& p: cnt)
        {
            for(int i = 0; i < p.second; i++) res.emplace_back(p.first);
        }
        return res;
    }
};

//without sort
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		vector<int> cnt(1001, 0);
		vector<int> res;
		for(int& num : arr1) cnt[num]++;
		for(int& num : arr2)
		{
			for(int i = 0; i < cnt[num]; i++)
			{
				res.emplace_back(num);
			}
			cnt[num] = 0;
		}
		for(int num = 0; num < 1001; num++)
		{
			for(int j = 0; j < cnt[num]; j++)
			{
				res.emplace_back(num);
			}
		}
		return res;
	}
};
