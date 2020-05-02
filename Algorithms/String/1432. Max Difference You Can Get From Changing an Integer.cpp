class Solution {
public:
    int maxDiff(int num) {
        std::string Max = to_string(num);
        std::string Min = Max;
        bool found = false;
        char origin;
        char to = '9';
        for(int i = 0; i < Max.size(); ++i)
        {
            if(!found && Max[i] != to)
            {
                origin = Max[i];
                Max[i] = to;
                found = true;
            }
            else if(found && Max[i] == origin)
            {
                Max[i] = to;
            }
        }
        
        found = false;
        to = '1';
        if(Min[0] != to)
        {
            origin = Min[0];
            found = true;
            Min[0] = to;
        }
        else
        {
            to = '0';
        }
        
        for(int i = 1; i < Min.size(); ++i)
        {
            if(!found && Min[i] != to && Min[i] != Min[0])
            {
                origin = Min[i];
                Min[i] = to;
                found = true;
            }
            else if(found && Min[i] == origin)
            {
                Min[i] = to;
            }
        }
        return std::stoi(Max) - std::stoi(Min);
    }
};
