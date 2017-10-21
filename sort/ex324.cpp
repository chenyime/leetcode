class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int n = nums.size();
        int index1 = n-1, index2 = (n-1)/2, index3 = n/2;
        for (int i = 0; i < n-1; i++) {
            if (i%2 == 0) {
                nums[i] = sorted[index2--];
            } else {
                nums[i] = sorted[index1--];
            }
        }
        if (n%2 == 1)
            nums[n-1] = sorted[0];
        else 
            nums[n-1] = sorted[index1];
    }
};