class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = -1, i = 0;
        while(i < s.size()) {
            int pos = t.find_first_of(s[i], index+1);
            if(pos == string::npos)
                return false;
            i++;
            index = pos;
        }
        return true;
    }
};