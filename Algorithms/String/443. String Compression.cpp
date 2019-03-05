class Solution {
public:
    int compress(vector<char>& chars) {
		int anchor = 0, write = 0;
		int len = chars.size();
		for(int read = 0; read < len; read += 1)
		{
			if(read + 1 == len || chars[read + 1] != chars[read])
			{
				chars[write++] = chars[read];
				if(read > anchor)
				{
					for(char& c : to_string(read - anchor + 1))
					{
						chars[write++] = c;	
					}
				}
				anchor = read + 1;
			}
		}
		return write;
	}
};

