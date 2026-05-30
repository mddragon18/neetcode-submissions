class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26]={0};
        if(s.length()!=t.length()) return 0;
        for(int i=0;i<s.length();i++) {
            int j=s[i]-'a';
            count[j]++;
            j=t[i]-'a';
            count[j]--;
        }
        for(int i=0;i<26;i++) if(count[i]!=0) return 0;
        return 1;
    }
};
