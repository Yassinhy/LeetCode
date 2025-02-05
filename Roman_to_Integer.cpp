class Solution {
public:
    int romanToInt(string s) {
        std::map<char, int> myMap;
        myMap['I'] = 1;
        myMap['V'] = 5;
        myMap['X'] = 10;
        myMap['L'] = 50;
        myMap['C'] = 100;
        myMap['D'] = 500;
        myMap['M'] = 1000;
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            if (myMap[s[i]] < myMap[s[i+1]]) {
                result = result - myMap[s[i]];
            } else {
                result = result + myMap[s[i]];
            }
        }
        return {result};
    }
};
