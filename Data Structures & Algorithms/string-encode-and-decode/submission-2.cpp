class Solution {
public:
    // concatenate the strings with a separator ??
    string encode(vector<string>& strs) {
        char sep='`';
        string encoded;
        for(string s : strs ) {
            encoded+=s+'`';
        }
        return encoded;
    }

    vector<string> decode(string s) {
        char sep='`';
        vector<string> decodedList;
        string x="";
        for(char ch : s) {
            if(ch!='`') x+=ch;
            else {
                decodedList.push_back(x);
                x="";
            }
        }
        return decodedList;
    }
};
