class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hms;
        unordered_map<char,int> hmt;

        for (char c : s) hms[c]++;
        for (char c : t) hmt[c]++;

        return hms == hmt;
    }
};
