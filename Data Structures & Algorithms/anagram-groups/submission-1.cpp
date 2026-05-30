class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> hm;
        for (string s : strs) {
            string key = s;
            sort(key.begin(),key.end());
            hm[key].push_back(s);
        }

        for(auto i:hm) {
            ans.push_back(i.second);
        }
        return ans;
    }
};
