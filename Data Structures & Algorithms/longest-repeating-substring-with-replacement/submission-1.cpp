class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> hm;
        int res = 0;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            hm[s[r]]++;
            int max_element = (hm.begin())->second;
            for(auto it = hm.begin(); it != hm.end(); ++it)
                if(it->second > max_element) max_element = it->second;
            
            while ((r-l+1-max_element) > k) {
                hm[s[l]]--;
                l++;
            }

            res = max(res,r-l+1); 
            
        }

        return res;
    }
};
