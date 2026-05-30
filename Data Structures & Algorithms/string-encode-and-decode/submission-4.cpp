class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded="";
        for (string s:strs) {
            string l = to_string(s.size());
            encoded+=l+"#"+s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        char ch; int i=0; int l = s.size();
        while(i<l) {
            string sseek;
            while(s[i]!='#') sseek+=s[i++];
            int seek=stoi(sseek);
            string sub = s.substr(i+1,seek);
            decoded.push_back(sub);
            i=i+1+seek;
        }

        return decoded;
    }
};
