class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if (nums.size() == 0) return "";
        string res = to_string(nums[0]);
        if (nums.size() > 2) {
            res += "/(";
            for (int i = 1; i < nums.size()-1; i++) {
                res += to_string(nums[i]);
                res += "/";
            }
            res += to_string(nums[nums.size()-1]);
            res += ")";
        } else if (nums.size() == 2) {
            res += "/";
            res += to_string(nums[nums.size()-1]);
        }
        return res;
    }
};