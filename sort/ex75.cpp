class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() == 1)
            return;
        int start = 0, end = nums.size()-1, now = 0;
        while(now <= end) {
            if (nums[now] == 0) {
                swap(nums, now, start);
                start++;
                now++;
            } else if (nums[now] == 2) {
                swap(nums, now, end);
                end--;
            } else if (nums[now] == 1) {
                now++;
            }
        }
        return;
    }
    
    void swap(vector<int>& nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
};