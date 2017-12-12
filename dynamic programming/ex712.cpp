class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        int dp[1000][1000];
        for (int i = 0; i <= len1; i++) {
            dp[i][0] = sum(s1, i);
        }
        for (int j = 1; j <= len2; j++) {
            dp[0][j] = sum(s2, j);
        }
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j]+(int)(s1[i-1]), dp[i][j-1]+(int)(s2[j-1]));
                }
            }
        }
        return dp[len1][len2];
    }
    
    int sum(string s, int j) {
        int res = 0;
        for(int i = 0; i <= j; i++) {
            res += (int)(s[i-1]);
        }
        return res;
    }
};