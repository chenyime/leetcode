class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size(), res = 0;
        if (size == 0)
            return res;
        sort(citations.begin(), citations.end());
        for (int i = 0; i < size; i++) {
            if (size - i <= citations[i] && res < size - i)
                res = size - i;
        }
        return res;
    }
};