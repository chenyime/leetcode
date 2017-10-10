class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        vector<int> tempNum(n, 0);
        if(A[2]-A[1] == A[1]-A[0])
            tempNum[2] = 1;
        int res = tempNum[2];
        for (int i = 3; i < n; i++) {
            if(A[i]-A[i-1] == A[i-1]-A[i-2])
                tempNum[i] = tempNum[i-1] + 1;
            res += tempNum[i];
        }
        return res;
    }
};