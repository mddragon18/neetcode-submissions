class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hst;
        unordered_map<char, int> window;
        int have = 0;
        int need;

        for (char ch : t) hst[ch]++;
        need = hst.size();
        int bestStart = 0, bestLen = INT_MAX;
        int i = 0, j = 0;
        for (j = 0; j < s.length(); j++) {
            window[s[j]]++;
            if (hst[s[j]] == window[s[j]] && hst.count(s[j])) have++;
            while (have >= need) {
                if (j - i + 1 < bestLen) {
                    bestStart = i;
                    bestLen = j - i + 1;
                }
                window[s[i]]--;
                if (hst.count(s[i]) && window[s[i]] < hst[s[i]]) have--;
                i++;
            }
        }

        if (bestLen == INT_MAX) return "";
        return s.substr(bestStart, bestLen);
    }
};
