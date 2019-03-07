class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> addresses;
		for(string& email : emails)
		{
			string address = "";
			char flag = ' ';
			for(char& c : email)
			{
				switch(flag)
				{
					case ' ':
						if(c == '+' || c == '@')
						{
							flag = c;
						}
						else if(c != '.') address += c;
						break;
					case '+':
						if(c == '@')
						{
							flag = c;
						}
						break;
					case '@':
						address += c;
						break;
				}
			}
			addresses.insert(address);
		}
		return addresses.size(); 
    }
};

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> addresses;
		for(string& email : emails)
		{
			int index = email.find('@');
			string local = email.substr(0, index);
			string domin = email.substr(index);

			int plusIndex = local.find('+');
			if(plusIndex != string::npos)
			{
				local = local.substr(0, plusIndex);
			}
			string newLocal = "";
			for(char& c : local)
			{
				if(c != '.') 
				{
					newLocal += c;
				}
			}
			addresses.insert(newLocal.append(domin));
		}
		return addresses.size();
	}
};
