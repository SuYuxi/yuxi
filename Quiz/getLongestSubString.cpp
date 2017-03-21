#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

//Declare the function that getting the longest substring that meets mode requirement
vector<string> getLongestSubString(string inputData, string mode);

//Main program that call "getLongestSubString" function to get the Longest Sub String with expected mode
int main() {
    string inputData;
    string mode;
    vector<string> longestSubStr;
    cout << "Please input process mode from \"Ascend\", \"Descend\" or \"Equal\" (without quotation mark)" << endl;
    cin >> mode;
    cout << "Please input a string to retrieve the longest substring" << endl;
    cin >> inputData;
    longestSubStr = getLongestSubString(inputData, mode);
    longestSubStr = getLongestSubString(inputData, mode);
    cout << "The longest " + mode + " Value Part String showed as below:"<< endl;
    for (const string& subStr : longestSubStr) {
        cout << subStr << endl;
    }
    return 0;
}

//Define function that getting the longest substring that meets mode requirement
vector<string> getLongestSubString(string inputStr, string mode) {
    const vector<string> modeType = {"Ascend", "Descend", "Equal"};
    //Validate if the inputs are legal, otherwise throw an input error
    if(find(modeType.begin(), modeType.end(), mode) == modeType.end()) {
        cout << "Mode error! Mode can only be \"Ascend\", \"Descend\" or \"Equal\"!" << endl;
        throw exception();
    }
    //Validate if the inputs only include digits or only include alphabets, otherwise throw an input error
    vector<bool> flag = {0,0};
    for (char& c : inputStr) {
        if(c >= 48 && c <= 57) {
            flag[0] = 1;
        }
        else if((c >= 97 && c <= 122) || (c >= 65 && c <= 90)) {
            flag[1] = 1;
        }
        else {
            flag = {1, 1};
        }
        if(flag[0] & flag[1]) {
            cout << "Input error! Input string can only include digits or only include alphabets!" << endl;
            throw exception();
        }
    }
    //Define compare function with the corresponding comparison lambda expression (use -std=c++11 when compiling)
    bool (*compare)(char a, char b);
    if(mode == "Ascend") {
        compare = [](char a, char b) -> bool {return a > b;};
    }
    else if(mode == "Descend") {
        compare = [](char a, char b) -> bool {return a < b;};
    }
    else {
        compare = [](char a, char b) -> bool {return a == b;};
    }
    //Use Two Pointer algorithm to get the longest substring that meets mode requirement
    int inputLength = inputStr.size();
    if(inputLength <= 1) {
        vector<string> longestSubStr;
        longestSubStr.push_back(inputStr);
        return longestSubStr;
    }
    set<string> longestSubStr;
    int left = 0, right = 0;
    int maxlen = 0, subStrLen;
    vector<int> positions;
    while(left < inputLength) {
        right += 1;
        while(right < inputLength) {
            if(compare(inputStr[right], inputStr[right-1])) {
                right += 1;
            }
            else {
                break;
            }
        }
        subStrLen = right - left;
        if(subStrLen > maxlen) {
            maxlen = subStrLen;
            positions.clear();
            positions.push_back(left);
        }
        else if(subStrLen == maxlen) {
            positions.push_back(left);
        }
        left = right;
    }
    for(const int& pos : positions) {
        longestSubStr.insert(inputStr.substr(pos, maxlen));
    }
    vector<string> sortedLongestSubStr(longestSubStr.begin(), longestSubStr.end());
    sort(sortedLongestSubStr.begin(), sortedLongestSubStr.end());
    return sortedLongestSubStr;
}
