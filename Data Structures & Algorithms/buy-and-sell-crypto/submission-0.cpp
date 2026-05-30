class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int profit=0;
        for(int i=0; i<prices.size();i++) {
            buy = prices[i];
            for(int j=i+1;j<prices.size();j++) {
                if((prices[j]-buy) > profit && i<j) 
                profit = prices[j] - buy;
            }
        }
        return profit;
    }
};
