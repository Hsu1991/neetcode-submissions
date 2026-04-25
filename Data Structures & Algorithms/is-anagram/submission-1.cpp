class Solution {
public:
    bool isAnagram(string s, string t) {
        int sum_s = 0, sum_t = 0;
        // check two string's length
        if(s.length() != t.length())
            return false;
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            sum_s += s[i];
            sum_t += t[i];
        }
        return sum_s == sum_t;
    }
};
