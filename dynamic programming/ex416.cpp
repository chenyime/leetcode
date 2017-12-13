class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size(), sum = 0, half = 0;
        for(int i = 0; i < len; i++) {
            sum += nums[i];
        }
        if (sum & 1)
            return false;
        half = sum/2;
        vector<int> dp(half+1, 0);
        dp[0] = 1;
        for (int i = 0; i < len; i++) {
            for (int j = half; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[half];
    }
};