//TreeMap
class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
		map<int, int> vals; //<val, inx>
		int size = A.size();
		vector<bool> lowerJump(size, false);
		vector<bool> higherJump(size, false);
		lowerJump[size-1] = true;
		higherJump[size-1] = true;
		for(int i = size - 1; i >= 0; i--)
		{
			map<int, int>::iterator upper = vals.lower_bound(A[i]);
			map<int, int>::iterator lower = vals.upper_bound(A[i]);
			if(upper != vals.end())
			{
				higherJump[i] = lowerJump[upper->second];
			}
			if(lower != vals.end() && lower != vals.begin())
			{
				lowerJump[i] = higherJump[(--lower)->second];
			}
			vals[A[i]] = i;
		}
		int res = 0;
		for(bool status : higherJump)
		{
			if(status) res++;
		}
		return res;
    }
};

//Stack
class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
		int size = A.size();
		vector<pair<int, int>> B;
		for(int i = 0; i < size; i++)
		{
			B.emplace_back(make_pair(A[i], i));
		}

		sort(B.begin(), B.end(), [](auto& a, auto& b){ return a.first == b.first ? a.second < b.second : a.first < b.first; });
		vector<int> oddNext = findNext(B);

		sort(B.begin(), B.end(), [](auto& a, auto& b){ return a.first == b.first ? a.second < b.second : a.first > b.first; });
		vector<int> evenNext = findNext(B);

		vector<bool> odd(size, false);
		vector<bool> even(size, false);
		odd[size-1] = true;
		even[size-1] = true;
		for(int i = size - 1; i >= 0; i--)
		{
			if(oddNext[i] != -1)
			{
				odd[i] = even[oddNext[i]];	
			}
			if(evenNext[i] != -1)
			{
				even[i] = odd[evenNext[i]];	
			}
		}

		int res = 0;
		for(bool status : odd)
		{
			if(status) res++;
		}
		return res;
    }

private:
	vector<int> findNext(vector<pair<int, int>>& pairs)
	{
		vector<int> nexts(pairs.size(), -1);
		vector<int> stack;
		for(auto& p : pairs) 
		{
			while(!stack.empty() && stack.back() < p.second)
			{
				nexts[stack.back()] = p.second;
				stack.pop_back();
			}
			stack.emplace_back(p.second);
		}
		return nexts;
	}
};
