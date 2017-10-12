class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        if(n > 10)
            n = 10;
        int result = 1;
        for(int i = 1; i <= n; i++) 
            result += getNum(i);
        return result;
    }
    
    int getNum(int n) {
        if(n == 0) {
            return 1;
        } else if(n == 1) {
            return 9;
        } else {
            int result = 9;
            for(int i = 0; i < n-1; i++) 
                result = result*(9-i);
            return result;
        }
    }
};