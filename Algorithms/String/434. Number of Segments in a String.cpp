class Solution {
public:
    int countSegments(string s) {
		int count = 0;
		char pre = ' ';
		for(char& c : s)
		{
			if(pre == ' ' && c != ' ')
			{
				count += 1;
			}
			pre = c;
		}
		return count;
    }
};
