class Solution {
public:
    int integerBreak(int n) {
        switch(n) {
            case 2:
                return 1;
                break;
            case 3:
                return 2;
                break;
            case 4:
                return 4;
                break;
        }
        int count = n/3;
        int temp = n%3;
        if (temp == 1) {
            return 4*getNum(count-1);
        } else if(temp == 0) {
            return getNum(count);
        } else {
            return 2*getNum(count);
        }
    }
    
    int getNum(int count) {
        int res = 1;
        for(int i = 0; i < count; i++) {
            res *= 3;
        }
        return res;
    }
};