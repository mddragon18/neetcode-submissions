class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;
        unordered_map<char,int> hs1;
        unordered_map<char,int> hs2;
        int l=0,r=0;
        for(char ch : s1) hs1[ch]++;
        // I think this is a fixed window style question where the size is len(s1)
        int k=s1.length();
        for(r=0;r<k;r++) hs2[s2[r]]++;
        if(hs1 == hs2) return true;
        for(r=k;r<s2.length();r++) {
            hs2[s2[l]]--;
            if(hs2[s2[l]]==0) hs2.erase(s2[l]);
            l++;
            hs2[s2[r]]++;
            if(hs1==hs2) return true;
        }
        
        return false;
    }
};
