#include <cmath>
#include <sstream>

class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
		vector<float> p;
		int sum = target;
		for(string& s : prices)
		{
            if(stof(s) != floor(stof(s))) p.emplace_back(stof(s) - floor(stof(s)));
			sum -= floor(stof(s));
		}
		if(sum < 0 || sum > p.size()) return "-1";
		sort(p.begin(), p.end(), greater<float>());
		float res = 0;
		for(int i = 0; i < p.size(); i++)
		{
			if(i < sum)
			{
				res += 1 - p[i];
			}
			else
			{
				res += p[i];
			}
		}
		//std::stringstream ss;
		//ss << std::fixed << std::setprecision(3) << res;
		//return ss.str();
		res = round(res * 1000) / 1000;
		string s = to_string(res);
		int i = s.find('.');
		if(i == string::npos) return s + ".000";
		return (s + "000").substr(0, i + 4);
    }
};
