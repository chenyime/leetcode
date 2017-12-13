class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0, min = INT_MAX, len = prices.size();
        for (int i = 0; i < len; i++) {
            min =  min < prices[i] ? min : prices[i];
            max = max > prices[i]-min ? max : prices[i]-min;
        }
        return max;
    }
};