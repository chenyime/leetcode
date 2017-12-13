class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        // sort(nums.begin(), nums.end());
        for (int j = 1; j <= target; j++) {
            for (int i = 0; i < len; i++) {
                if (j < nums[i])
                    continue;
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};