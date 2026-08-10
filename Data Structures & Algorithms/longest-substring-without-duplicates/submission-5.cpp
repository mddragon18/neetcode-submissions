class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashmap;
        int i = 0,j=0;
        int n = s.length();
        int maxLen = 0;
        for(j=0;j<n;j++) {
            hashmap[s[j]]++;
            while(hashmap[s[j]]>1) 
            {
                hashmap[s[i]]--;
                i++;
            }
            maxLen = max(maxLen,j-i+1);
        }
        return maxLen;
    }
};
