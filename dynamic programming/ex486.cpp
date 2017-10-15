class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> f(n+1, vector<int>(n+1, 0));
        vector<int> sum(n+1, 0);
        for (int i = 1; i <= n; i++) {         
            f[i][i] = nums[i-1];
            sum[i] = sum[i-1] + nums[i-1]; 
            //cout << i << ' ' << f[i][i] << ' ' << sum[i] << endl;
        }
        for (int k = 1; k < n; k++) {
            for (int i = 1; i+k <= n; i++) {
                int j = i + k;
                f[i][j] = max(sum[j-1]-sum[i-1]-f[i][j-1]+nums[j-1], sum[j]-sum[i]-f[i+1][j]+nums[i-1]);
                //cout << i << ' ' << j << ' ' << f[i][j] << endl;
            }
        }

            return f[1][n] >= sum[n]-f[1][n]? true: false;
    }
};