class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        vector<vector<string>> ans;
        vector<string> sorted=strs;
        for(string& x : sorted) {
            sort(x.begin(),x.end());
        }
        int flag[size]={0};

        for(int i=0;i<size;i++) {
            if(flag[i]==1) continue;
            flag[i]=1;
            vector<string> subList;
            string cur=sorted[i];
            subList.push_back(strs[i]);
            for(int j=i+1;j<size;j++) {
                if(cur==sorted[j] && flag[j]==0) {
                    subList.push_back(strs[j]);
                    flag[j]=1;
                }
            }
            ans.push_back(subList);
        }

        return ans;
    }
};
