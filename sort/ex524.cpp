class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for (int i = 0; i < d.size(); i++) {
            int num = d[i].size(), j = 0, k = 0;
            for (; j < s.size() && k < num; j++) {
                if (s[j] == d[i][k])
                    k++;
            }
            if (k == num && num >= res.size()) {
                if (num == res.size() && res < d[i])
                    continue;
                res = d[i];
            }
        }
        return res;
    }
};