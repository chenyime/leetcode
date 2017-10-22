class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int i = nums.size()-1;
        string res = "";
        sort(nums.begin(), nums.end(), compare);
        while (i >= 0) {
            res += to_string(nums[i]);
            cout << nums[i] << endl;
            i--;
            if (res[0] == '0') {
                res = res.substr(1);
            }
        }
        if (res == "")
            res = "0";
        return res;
    }
    
    static bool compare(int a, int b) {
        string a1 = to_string(a);
        string b1 = to_string(b);
        return a1+b1 < b1+a1;
    }
};