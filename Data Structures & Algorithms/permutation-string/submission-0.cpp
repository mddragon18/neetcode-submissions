class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        unordered_map<char,int> hm1;
        unordered_map<char,int> hm2;
        int k=s1.size();
        for(char ch:s1) hm1[ch]++;

        for(int i=0; i<k; i++) hm2[s2[i]]++;

        if(hm1==hm2) return true;

        for(int i=k; i<s2.length(); i++) {
            hm2[s2[i-k]]--;
            if (hm2[s2[i-k]] == 0)
            hm2.erase(s2[i-k]);
            hm2[s2[i]]++;

            if(hm1 == hm2) return true;
        }

        return false;
        

    }
};
