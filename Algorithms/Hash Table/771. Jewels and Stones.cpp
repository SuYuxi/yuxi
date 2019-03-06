class Solution {
public:
    int numJewelsInStones(string J, string S) {
		std::unordered_set<char> hash;		
		int count = 0;
		for(char& j : J)
		{
			hash.emplace(j);
		}
		for(char& s : S)
		{
			if(hash.count(s) > 0)
			{
				count += 1;
			}
		}
		return count; 
    }
};
