class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int len = nums.size(), sum = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
        }
        if (S > sum || S < -sum || (S+sum)%2) {
            return 0;
        }
        return canPartition(nums, (S+sum)/2);
    }
    
    int canPartition(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 0; i < len; i++) {
            for (int j = target; j >= nums[i]; j--) {
                if (dp[j-nums[i]]) {
                    dp[j] += dp[j-nums[i]];
                }
            }
        }
        return dp[target];
    }
};