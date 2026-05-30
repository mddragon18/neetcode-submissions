class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int i;
       int profit = 0;
       for(i=1;i<prices.size();i++) {
            profit = (prices[i]-prices[i-1] > profit) ?  prices[i]-prices[i-1] : profit;
            prices[i] = (prices[i] < prices[i-1]) ? prices[i] : prices[i-1]; 
       }
       return profit;
    }
};
