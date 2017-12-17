class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int len = nums.size();
        vector<int> num(10001, 0);
        vector<int> dp(10003, 0);
        for (int i = 0; i < len; i++) {
            num[nums[i]] += nums[i];
        }
        for (int i = 10000; i >= 0; i--) {
            dp[i] = max(num[i]+dp[i+2], dp[i+1]);
        }
        return dp[0];
    }
};