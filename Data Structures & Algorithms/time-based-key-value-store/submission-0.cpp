class TimeMap {

    unordered_map<string,vector<pair<int,string>>> hashmap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
         hashmap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!hashmap.count(key)) {
            return "";
        }
        auto& arr = hashmap[key];
        int l = 0;
        int h = arr.size()-1;
        int mid;
        string ans="";
        while(l <= h) {
            mid = (l+h)/2;

            if(arr[mid].first <= timestamp) {
                ans=arr[mid].second;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};
