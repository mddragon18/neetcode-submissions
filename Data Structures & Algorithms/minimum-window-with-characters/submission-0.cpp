class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        int formed=0;
        for(char ch:t) need[ch]++;
        int required = need.size();

        unordered_map<char,int> window;
        int l=0,bestLen=INT_MAX,bestStart=l;

        for(int r=0; r<s.length(); r++) {
            char c = s[r];
            window[c]++;
            if(need.count(c) && need[c]==window[c]) formed++;

            while(l<=r && formed==required) {
                if(r-l+1 < bestLen) {
                    bestLen=r-l+1;
                    bestStart=l;
                }
                window[s[l]]--;
                if(need.count(s[l]) && window[s[l]] < need[s[l]]) formed--;
                l++;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestStart,bestLen);
    }
};
