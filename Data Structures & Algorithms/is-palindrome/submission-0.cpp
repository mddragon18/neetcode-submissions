class Solution {
public:
    bool isPalindrome(string s) {
        int start=0;
        int end=s.length() - 1;

        while(end>start) {
            while(end>start && !isalnum(s[start])) start++;
            while(end>start && !isalnum(s[end])) end--;
            if(tolower(s[start]) != tolower(s[end])) return false;
            start++;
            end--;
        }

        return true;

    }
};